//#include <python3.5m/Python.h>
#include "cpythonTest.h"

cpythonTest::cpythonTest()
{
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

    PyObject* module = PyImport_ImportModule("python_test");

    PyObject* func = PyObject_GetAttrString(module, "test");

    PyObject_CallObject(func, NULL);


    Py_Finalize();
}
