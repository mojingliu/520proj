#!/usr/bin/env python

# WIG "array" generator.  In Python so it can run at school.
# Kamal Al-Marhubi

# Expects a single integer as its first argument, and optionally a
# filename for output.  Will output to stdout if none is given.

import sys  # for command line args

# filenames
htmls = "htmls"
schemas = "schemas"
globals = "globals"
functions = "functions"
sessions = "sessions"

usage = "Usage: First arg size, second (optional) filename for output."

# String definitions -- ugly, save yourself.

# simple strings here
ibsSchema = "schema IBS {\nint i;\nbool b;\nstring s;\n}\n"

arraySize = "int array_size() { return %d; }\n"


# Init parts are the opener, Loop parts are printed for every "array"
# index, End parts close.
arraySchema = ("schema Array {\n", "int i%(i)d;\nbool b%(i)d;\nstring s%(i)d;\n\n", "}\n")

arrayNew = ("tuple Array array_new() {\ntuple Array a;\na = tuple {\ni0 = 0, b0 = false, s0 = \"\"", ",\ni%(i)d = 0, b%(i)d = false, s%(i)d = \"\"", "\n};\nreturn a;\n}\n")

arrayGet = ("tuple IBS array_get(tuple Array a, int n) {\ntuple IBS res;\n", "if(n == %(i)d) {\nres.i = a.i%(i)d;\nres.b = a.b%(i)d;\nres.s = a.s%(i)d;\n}\n", "return res;\n}\n")

arrayInsert = ("tuple Array array_insert(tuple Array a, int n, tuple IBS val) {\n", "if(n == %(i)d) {\na.i%(i)d = val.i;\na.b%(i)d = val.b;\na.s%(i)d = val.s;\n}\nif(n < %(i)d) {\na.i%(i)d = a.i%(i1)d;\na.b%(i)d = a.b%(i1)d;\na.s%(i)d = a.s%(i1)d;\n}\n", "if(n == 0) {\na.i0 = val.i;\na.b0 = val.b;\na.s0 = val.s;\n}\nreturn a;\n}\n")

arraySet = ("tuple Array array_set(tuple Array a, int n, tuple IBS val) {\n", "if(n == %(i)d) {\na.i%(i)d = val.i;\na.b%(i)d = val.b;\na.s%(i)d = val.s;\n}\n", "return a;\n}\n")


def putfile(fn, out):
    """ writes contents of file named 'fn' to file object 'out'"""
    f = open(fn)
    try:
        for line in f:
            print >> out, line,
    finally:
        f.close()

def putdefn(defn, size, out, start = 0):
    (init, loop, end) = defn
    print >> out, init,
    for i in xrange(start,size):
        print >> out, loop % {'i': i, 'i1' : i-1 },
    print >> out, end,

def putdefn2(defn, size, out):
    (init, loop, end) = defn
    print >> out, init,
    for i in xrange(size-1,0,-1):
        print >> out, loop % {'i': i, 'i1' : i-1 },
    print >> out, end,

def main(argv = None):
    if argv is None:
        argv = sys.argv
    if not 2 <= len(argv) <= 3:
        print usage
        return
    size = int(argv[1])
    if len(argv) > 2:
        out = open(argv[2], 'w')
    else:
        out = sys.stdout
    print >> out, "service {"
    print >> out, "/* begin htmls section */"
    putfile(htmls, out)
    print >> out, "/* end htmls section */"
    print >> out, "/* begin schemas section */"
    putfile(schemas, out)
    print >> out, ibsSchema
    putdefn(arraySchema, size, out)
    print >> out, "/* end schemas section */"
    print >> out, "/* begin globals section */"
    putfile(globals, out)
    print >> out, "/* end globals section */"
    print >> out, "/* begin functions section */"
    putfile(functions,out)
    print >> out, arraySize %size
    putdefn(arrayNew, size, out, 1)
    putdefn(arrayGet, size, out)
    putdefn2(arrayInsert, size, out)
    putdefn(arraySet, size, out)
    print >> out, "/* end functions section */"
    print >> out, "/* begin session section */"
    putfile(sessions, out)
    print >> out, "/* end session section */"
    print >> out, "}"
    out.close()
    return

# GVR says this si good
if __name__ == '__main__':
    sys.exit(main())
            
