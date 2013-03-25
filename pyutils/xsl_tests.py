import unittest
from tests_utils import execute_test
import sys


class XSLTest(unittest.TestCase):
    test_folder = "tests/"

    def perror(self, expected, result):
        print "######Expected##########"
        print expected
        print "######Result##########"
        print result
        print "################"

    def simple_test(self, n):
        result, err = execute_test([self.test_folder + "simple" + str(n) + ".xml", "-x" + self.test_folder + "simple" + str(n) + ".xsl"])
        f = open(self.test_folder + "simple" + str(n) + ".html", 'r')
        expected = f.read()
        f.close()
        
        if (result != expected):
            self.perror(expected, result)
            sys.stderr.write(err)

        self.assertEqual(result, expected, "the output is wrong")

    def test_simple1(self):
        self.simple_test(1)

    def test_simple2(self):
        self.simple_test(2)

    def test_simple3(self):
        self.simple_test(3)
    
    def test_simple4(self):
        self.simple_test(4)
    
    def test_simple5(self):
        self.simple_test(5)
    
    def test_simple6(self):
        self.simple_test(6)
    
    def test_simple7(self):
        self.simple_test(7)
    
    def test_simple8(self):
        self.simple_test(8)
    
    def test_simple9(self):
        self.simple_test(9)

if __name__ == '__main__':
    unittest.main()
