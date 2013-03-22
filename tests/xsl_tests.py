import unittest
from tests_utils import execute_test


class XSLTest(unittest.TestCase):
    def simple_test(self, n):
        tokens = {"testId": n, "testDir": "tests"}
        testSrc = ["{testDir}/simple{testId}.xml", "",
                   "{testDir}/simple{testId}.xsl"]
        args = [f.format(**tokens) for f in testSrc]
        expectedfile = "{testDir}/simple{testId}.html".format(**tokens)
        f = open(expectedfile, 'r')
        expected = open(expectedfile, "r").read()

        result = execute_test(args)
        expected = f.read()
        f.close()

        if (result != expected):
            print "################"
            print result
            print "################"
            print expected
            print "################"

        self.assertEqual(result, expected, "the output is wrong")

    def test_simple1(self):
        print 1
        self.simple_test(1)

    def test_simple2(self):
        self.simple_test(2)

    def test_simple3(self):
        self.simple_test(3)

if __name__ == '__main__':
    unittest.main()
