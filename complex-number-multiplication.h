// https://leetcode.com/problems/complex-number-multiplication/

// 537. Complex Number Multiplication
// A complex number can be represented as a string on the form "real+imaginaryi" where:

// real is the real part and is an integer in the range [-100, 100].
// imaginary is the imaginary part and is an integer in the range [-100, 100].
// i2 == -1.
// Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

// Example 1:

// Input: num1 = "1+1i", num2 = "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
// Example 2:

// Input: num1 = "1+-1i", num2 = "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

// Constraints:

// num1 and num2 are valid complex numbers.

// Algorithm

// Multiplication of two complex numbers can be done as:
// (a+ib)×(x+iy)=ax+i^2by+i(bx+ay)=ax−by+i(bx+ay)

// We simply split up the real and the imaginary parts of the given complex strings based on the '+' and the 'i' symbols. We store the real parts of the two strings aa and bb as x[0]x[0] and y[0]y[0] respectively and the imaginary parts as x[1]x[1] and y[1]y[1] respectively. Then, we multiply the real and the imaginary parts as required after converting the extracted parts into integers. Then, we again form the return string in the required format and return the result.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Complex Number Multiplication.
// Memory Usage: 6.1 MB, less than 11.94% of C++ online submissions for Complex Number Multiplication.

class Solution
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        // Get the strings in the format needed by complex class
        complex<int> c1 = getComplexNumber(num1), c2 = getComplexNumber(num2);
        auto res = c1 * c2;

        string result = to_string(res.real()) + "+" + to_string(res.imag()) + "i";
        return result;
    }

    complex<int> getComplexNumber(string n)
    {
        string res("(");
        for (int i = 0; i < n.size() - 1; i++)
        {
            if (n[i] == '+')
            {
                res += ',';
            }
            else
            {
                res += n[i];
            }
        }
        res += ")";
        std::complex<int> c;
        std::istringstream is(res);
        is >> c;
        return c;
    }
};

// Using sscanf
string complexNumberMultiply(string a, string b)
{
    int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    sscanf(a.c_str(), "%d+%di", &a1, &b1);
    sscanf(b.c_str(), "%d+%di", &a2, &b2);
    return to_string(a1 * a2 - b1 * b2) + "+" + to_string(a1 * b2 + a2 * b1) + "i";
}
