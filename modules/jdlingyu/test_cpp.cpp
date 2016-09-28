#include <python3.5m/Python.h>
#include <iostream>

int main(int argc, char* argv[])
{
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

    PyObject* modules = PyImport_ImportModule("gcmain");
    PyObject* func = PyObject_GetAttrString(modules, "getMainPage");

    PyObject* arg = Py_BuildValue("(s)", "1");

    PyObject* result = PyObject_CallObject(func, arg);

    std::cout << int(result) << std::endl;

    std::cout << PyTuple_Check(result) << std::endl;


    int size = PySequence_Size(result);

    PyObject* each = NULL;
    PyObject* tmp = NULL;

    for(int t1 = 0; t1 < size; t1 ++)
    {

	each = PyTuple_GetItem(result, t1);
	for(int t2 = 0; t2 < 5; t2 ++)
	{
	    tmp = PyTuple_GetItem(each, t2);
	    if(t2 == 0 || t2 == 2)
	    {
		std::cout << PyLong_AsLong(tmp) << std::endl;
		continue;
	    }
	    else if(t2 == 1 || t2 == 3 || t2 == 4)
	    {
		std::cout << PyByteArray_AsString(tmp) << std::endl;
		continue;

	    }
	}
	std::cout << "______________________" << std::endl;
    }


    Py_Finalize();

    return 1;

}
