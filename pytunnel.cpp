#include <boost/python.hpp>

char const *greet()
{
    return "hi, tunnel!";
}

BOOST_PYTHON_MODULE(pytunnel)
{
    using namespace boost::python;
    def("greet", greet);
}