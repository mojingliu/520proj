import sys
import os
import random
import pickle

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
        self.variables[index] = val

admit_one = False
counter = 0
v = VarStack(None, {
    "msg0": "",
    "msg1": "",
    })
sid = 0
receives = {}

def html_Logon():
    print "I'm logon!"

def html_Update(p_msg0, p_msg1):
    print "Update %s %s" % (p_msg0, p_msg1, )

def html_ByeBye(p_conns, p_msgs):
    print "ByeBye %s %s" % (p_conns, p_msgs, )

def show(html, num, **kwargs):
    global sid
    global counter
    counter = num
    if sid == 0:
        sid = str(random.randint(1, 200000))
    save_context()
    html(**kwargs)
    print "(session id: %s)" % sid
    sys.exit()

def exit(html, **kwargs):
    # delete entry file or something
    if sid != 0:
        os.remove(sid + ".ws")
    html(**kwargs)
    sys.exit()

def save_context():
    global counter
    global v
    with open(sid + ".ws", "w") as f:
        pickle.dump((counter, v), f)
    # save to either a random file, or the old file

def load_context():
    global v
    pass    # load from the given file and save to context

def push_context(new_context):
    global v
    v = VarStack(v, new_context)    # push onto the stack

def pop_context():
    global v
    v = v.parent

def session_Chat():
    global admit_one
    global counter
    global v
    if counter <= 0:
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

        show(html_Logon, 1)
    if counter == 1:  # receives
        v["name"] = receives["name"]
        counter = 0
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
            if counter == 2:
                v["msg"] = receives["msg"]
                v["quit"] = receives["quit"]
                counter = 0
            if counter <= 2:
                v["connections"] = v["connections"] + 1
                if (v["msg"] != ""):
                    push_context({
                    })
                    v["written"] = v["written"] + 1
                    v["msg0"] = v["msg1"]
                    v["msg1"] = v["name"] + ">" + v["msg"]
                    pop_context()
            pop_context()
    exit(html_ByeBye, p_conns=v["connections"], p_msgs=v["written"])

if __name__ == "__main__":
    sessions = {"Chat":session_Chat}
    if len(sys.argv) < 2 or sys.argv[1] not in sessions:
        print "You did not enter a valid session name.\nTry one of these:"
        for s in sessions:
            print " -", s
        sys.exit()
    if len(sys.argv) >= 3:
        try:
            with open(sys.argv[2] + ".ws", "r") as f:
                sid = sys.argv[2]
                counter, v = pickle.load(f)
        except IOError as e:
            print "Your session key is not valid.\nTry one of the sessions below for a new key"
            for s in sessions:
                print " -", s
            sys.exit()
        for i in sys.argv[3:]:
            key, _, val = i.partition("=")
            receives[key] = val
    sessions[sys.argv[1]]()