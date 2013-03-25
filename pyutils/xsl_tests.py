import unittest
from tests_utils import execute_test
import sys


class XSLTest(unittest.TestCase):
    test_folder = "tests/"

    def perror(self, expected, result):
        print ""
        print "######Expected##########"
        print expected
        print "######Result##########"
        print result
        print "################"

    def __test_xsl(self, xml_filename, xsl_filename, html_filename):
        result, err = execute_test([self.test_folder + xml_filename, "-x" + self.test_folder + xsl_filename])
        f = open(self.test_folder + html_filename, 'r')
        expected = f.read()
        f.close()
        
        if (result != expected):
            self.perror(expected, result)
            sys.stderr.write("\n@@@@@@@@@@@@@@@@\n")
            sys.stderr.write(err)
            sys.stderr.write("\n@@@@@@@@@@@@@@@@\n")

        self.assertEqual(result, expected, "the output is wrong")

    def simple_test(self, n):
        n2 = str(n)
        return self.__test_xsl("simple" + n2 + ".xml", "simple" + n2 + ".xsl", "simple" + n2 + ".html")

    def complex_test(self, n):
            n2 = str(n)
            return self.__test_xsl("complex" + n2 + ".xml", "complex" + n2 + ".xsl", "complex" + n2 + ".html")

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
    
    def test_complex1(self):
        self.complex_test(1)

    def test_complex2(self):
        self.complex_test(2)

    def test_complex3(self):
        self.complex_test(3)

    def test_complex4(self):
        self.complex_test(4)

    def test_complex5(self):
        self.complex_test(5)

    def test_complex6(self):
        self.complex_test(6)

    def test_complex7(self):
        self.complex_test(7)

if __name__ == '__main__':
    unittest.main()
