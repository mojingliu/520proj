import sys

class VarStack(object):
    def __init__(self, parent, variables):
        self.parent = parent
        self.variables = variables

    def __getitem__(self, index):
        while self is not None and index not in self.variables:
            self = self.parent
        if self is None:
            raise AttributeError
        return self.variables[index]

    def __setitem__(self, index, val):
        while self is not None and index not in self.variables:
            self = self.parent
        if self is None:
            raise AttributeError
        return self.variables[index] = val

admit_one = False
counter = 0
v = None

def html_Logon(p_name):
    print "I'm logon! %s %s" % (p_name, )

def html_Update(p_msg0, p_msg1):
    print "Update %s %s" % (p_msg0, p_msg1, )

def html_ByeBye(p_conns, p_msgs):
    print "ByeBye %s %s" % (p_conns, p_msgs, )

def show(html, num, **kwargs):
    save_context()
    html(**kwargs)
    sys.exit()

def exit(html, **kwargs):
    # delete entry file or something
    html(**kwargs)
    sys.exit()

def save_context():
    pass    # save to either a random file, or the old file

def load_context():
    global v
    pass    # load from the given file and save to context

def push_context(new_context):
    global v
    v = VarStack(v, new_context)
    pass    # push onto the stack

def pop_context():
    global v
    v = v.parent

def session_Chat():
    global admit_one
    global counter
    global v
    if counter != 0:    # this code always at start of session
        load_context()
    else:  # this only happens on first run
        push_context({
            "name":"",
            "msg":"",
            "quit":"",
            "connections":0,
            "written":0,
        })

        v["connections"] = 0
        v["written"] = 0
        v["quit"] = "no"

        show(html_Logon, 1, p_name=v["name"])
    if counter <= 1:  # always if statements after shows, contains all commands
        x = 5         # up to the next show or conditional

    if counter <= 2:  # only do the while loop if you're less than the highest show in it
        if 2 <= counter <= 2:  # the range of shows in while loop (may be the same)
            admit_one = True
        while (admit_one or
                v["quit"] != "yes"):
            admit_one = False  # this is always the first line of compound statements
            if counter <= 1:
                push_context({
                })
                show(html_Update, 2, p_msg0=v["msg0"], p_msg1=v["msg1"])
            if counter <= 2:
                v["connections"] = v["connections"] + 1
                if (v["msg"] != ""):
                    push_context({
                    })
                    v["written"] = v["written"] + 1
                    v["msg0"] = v["msg1"]
                    v["msg1"] = v["name"] + ">" + v["msg"]
    exit(html_ByeBye, p_conns=v["connections"], p_msgs=v["written"])
