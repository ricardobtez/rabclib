# generate_unit_tests script
# Author: Ricardo Benitez

import os
import queue
import re

HEADER_FILENAME = "./test/inc/test_generated.h"
IGNORE_FILES = ["test_common.h", "test_generated.h"]

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
            for line in f:
                test = parse_testcase(line)
                if (test):
                    test_cases.append(test)
    return test_cases

def generate_header(test_cases, filename):
    print("\nTest cases found:", len(test_cases))
    with open(filename, "w") as f:
        f.write("/* Auto generated file */\n")
        f.write("#ifndef TEST_GENERATED_H\n")
        f.write("#define TEST_GENERATED_H\n")
        f.write("#include \"test_common.h\"\n")
        f.write("const struct CMUnitTest tests[] =\n")
        f.write("{\n")
        for test in test_cases:
            line = "    cmocka_unit_test(" + test + "),\n"
            f.write(line)
        f.write("};\n")
        f.write("#endif /* TEST_GENERATED_H */\n")
        f.write("\n")
    pass

# Use regular expression to parse the test case and obtain the name of the test case
def parse_testcase(line):
    test_case = None
    p = re.compile('\S*_test')
    m = p.search(line)
    if (m):
        test_case = m.group()
    return test_case

def main():
    #print("* Identifying the files to search the test cases from")
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
