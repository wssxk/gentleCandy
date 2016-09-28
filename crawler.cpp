#include <python3.5m/Python.h>
#include <iostream>
#include <string.h>

#include "crawler.h"


QList<imgHandle>* getMainPagePython(char *name, int page)
{
    Py_Initialize();


    char* path = new char[50];
    char* pageNum = new char[5];

    path[0] = '\0';
    strcat(path, "sys.path.append('./modules/");
    strcat(path, name);
    strcat(path, "')");



    sprintf(pageNum, "%d", page);

    std::cout << path << "::" << pageNum <<std::endl;

    PyRun_SimpleString("import sys");
//    PyRun_SimpleString("sys.path.append('./modules/jdlingyu')");
    PyRun_SimpleString(path);

    PyObject* module = PyImport_ImportModule("gcmain");
    PyObject* func = PyObject_GetAttrString(module, "getMainPage");

    PyObject* arg = Py_BuildValue("(s)", pageNum);

    PyObject* tuple = PyObject_CallObject(func, arg);

    QList<imgHandle>* result = new QList<imgHandle>;

    int size = PyTuple_Size(tuple);

    PyObject* each = NULL;
    //QObject* tmp = NULL;

    imgHandle* handle = NULL;

    int st;
    char* sg;
    int pn;
    char* si;
    char* sit;
    //char* module;

    for(int t1 = 0; t1 < size; t1 ++)
    {
        each = PyTuple_GetItem(tuple, t1);
        for(int t2 = 0; t2 < 5; t2 ++)
        {
            switch (t2) {
            case 0:
                st =  PyLong_AsLong(PyTuple_GetItem(each, t2));
                std::cout << st << std::endl;
                break;
            case 1:
                sg = PyByteArray_AsString(PyTuple_GetItem(each, t2));
                std::cout << sg << std::endl;
                break;
            case 2:
                pn = PyLong_AsLong(PyTuple_GetItem(each, t2));
                std::cout << pn << std::endl;
                break;
            case 3:
                si = PyByteArray_AsString(PyTuple_GetItem(each, t2));
                std::cout << si << std::endl;
                break;
            case 4:
                sit = PyByteArray_AsString(PyTuple_GetItem(each, t2));
                std::cout << sit << std::endl;
                break;
            default:
                break;
            }
        }
        handle = new imgHandle(st, sg, pn, si, sit, name);
        result->append(*handle);
        std::cout << "__________" << std::endl;

    }


    Py_Finalize();

    return result;

}


QList<imgHandle>* getCatalogPython(char *name, char *site)
{
    Py_Initialize();


    char* path = new char[50];
    //char* pageNum = new char[5];

    path[0] = '\0';
    strcat(path, "sys.path.append('./modules/");
    strcat(path, name);
    strcat(path, "')");



    //sprintf(pageNum, "%d", page);

    //std::cout << path << "::" << pageNum <<std::endl;

    PyRun_SimpleString("import sys");
//    PyRun_SimpleString("sys.path.append('./modules/jdlingyu')");
    PyRun_SimpleString(path);

    PyObject* module = PyImport_ImportModule("gcmain");
    PyObject* func = PyObject_GetAttrString(module, "getCatalog");

    PyObject* arg = Py_BuildValue("(s)", site);

    PyObject* tuple = PyObject_CallObject(func, arg);

    QList<imgHandle>* result = new QList<imgHandle>;

    int size = PyTuple_Size(tuple);

    PyObject* each = NULL;
    //QObject* tmp = NULL;

    imgHandle* handle = NULL;

    int st;
    char* sg;
    int pn;
    char* si;
    char* sit;
    //char* module;

    for(int t1 = 0; t1 < size; t1 ++)
    {
        each = PyTuple_GetItem(tuple, t1);
        for(int t2 = 0; t2 < 5; t2 ++)
        {
            switch (t2) {
            case 0:
                st =  PyLong_AsLong(PyTuple_GetItem(each, t2));
                std::cout << st << std::endl;
                break;
            case 1:
                sg = PyByteArray_AsString(PyTuple_GetItem(each, t2));
                std::cout << sg << std::endl;
                break;
            case 2:
                pn = PyLong_AsLong(PyTuple_GetItem(each, t2));
                std::cout << pn << std::endl;
                break;
            case 3:
                si = PyByteArray_AsString(PyTuple_GetItem(each, t2));
                std::cout << si << std::endl;
                break;
            case 4:
                sit = PyByteArray_AsString(PyTuple_GetItem(each, t2));
                std::cout << sit << std::endl;
                break;
            default:
                break;
            }
        }
        handle = new imgHandle(st, sg, pn, si, sit, name);
        result->append(*handle);
        std::cout << "__________" << std::endl;

    }


    Py_Finalize();

    return result;


}
