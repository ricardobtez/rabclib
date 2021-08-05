# generate_unit_tests script
# Author: Ricardo Benitez

import os
import queue
import re

HEADER_FILENAME = "./test/inc/test_generated.h"
IGNORE_FILES = ["test_common.h", "test_generated.h"]

class CTestCase:
    def __init__(self, filename):
        self.filename = filename
        self.test_cases = []
    def append(self, test_case):
        self.test_cases.append(test_case)
    def getFilename(self):
        return self.filename
    def getTestCases(self):
        return self.test_cases

def obtain_files():
    files = []
    dirs = os.scandir("./test/")
    finished = False
    q = queue.Queue()
    
    while(finished == False):
        if (dirs != None):
            for dir in dirs:
                q.put(dir)
            dirs = None
        try:
            item = q.get(False)
            if (item.is_file()):
                if (item.name not in IGNORE_FILES and item.name[-2:] == ".h"):
                    files.append(item.path)
            elif (item.is_dir()):
                dirs = os.scandir(item.path)
        except:
            finished = True
    return files

def obtain_test_cases(files):
    test_cases = []
    print("Files found with test cases:")
    for file in files:
        print(file)
    
    for file in files:
        with open(file, "r") as f:
            testCase = CTestCase(file)
            for line in f:
                test = parse_testcase(line)
                if (test):
                    testCase.append(test)
            if (len(testCase.getTestCases())):
                test_cases.append(testCase)
    return test_cases

def generate_header(test_cases, filename):
    counter = 0
    template = open("tools/generated_header_template.h", "r")
    includeKey = "#include"
    key = "{"
    foundKey = False

    if (template):
        with open(filename, "w") as f:
            while (foundKey == False):
                l = template.readline()
                if (includeKey in l):
                    foundKey = True
                f.write(l)
            foundKey = False

            for file in test_cases:
                #print(file)
                p = re.compile("\/test_\S*")
                m = p.search(file.getFilename())
                if (m):
                    f.write("#include \"" + m.group()[1:] + "\"\n")
            
            while (foundKey == False):
                l = template.readline()
                if (key in l):
                    foundKey = True
                f.write(l)
            foundKey = False

            for file in test_cases:
                for test in file.getTestCases():
                    counter = counter + 1
                    line = "    cmocka_unit_test(" + test + "),\n"
                    f.write(line)
            l = template.readline()

            while (l):
                l = template.readline()
                f.write(l)
    template.close()

    print("Test cases found: ", counter)

# Use regular expression to parse the test case and obtain the name of the test case
def parse_testcase(line):
    test_case = None
    p = re.compile('\S*_test')
    m = p.search(line)
    if (m):
        test_case = m.group()
    return test_case

def main():
    files = obtain_files()
    test_cases = obtain_test_cases(files)
    generate_header(test_cases, HEADER_FILENAME)


if __name__ == "__main__":
    print("******************************")
    print("* Start generate_unit_tests.py script")
    print("******************************\n")

    main()

    print("******************************")
    print("* End generate_unit_tests.py script")
    print("******************************\n")
