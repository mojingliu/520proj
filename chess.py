import sys
import os
import random
import pickle

class VarStack(object):
	def __init__(self, parent, variables):
		self.parent = parent
		self.variables = variables

	def __getitem__(self, index):
		if index not in self.variables:
			if self.parent is None:
				raise AttributeError
			return self.parent[index]
		return self.variables[index]

	def __setitem__(self, index, val):
		if index not in self.variables:
			if self.parent is None:
				raise AttributeError
			self.parent[index] = val
			return
		self.variables[index] = val

class FnStack(object):
	def __init__(self, parent, variables):
		self.parent = parent
		self.variables = variables

	def __getitem__(self, index):
		if index not in self.variables:
			while self.parent is not None:
				self = self.parent
		if index not in self.variables:
			raise AttributeError
		return self.variables[index]

	def __setitem__(self, index, val):
		if index not in self.variables:
			while self.parent is not None:
				self = self.parent
		if index not in self.variables:
			raise AttributeError
		self.variables[index] = val

admit_one = False
counter = 0
v = VarStack(None, {
	"row1": schema_row(),
	"row2": schema_row(),
	"row3": schema_row(),
	"row4": schema_row(),
	"row5": schema_row(),
	"row6": schema_row(),
	"row7": schema_row(),
	"row8": schema_row(),
	"turn": False
	})
sid = 0
receives = {}

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

def function_context(new_context):
	global v
	v = FnStack(v, new_context)

def pop_context():
	global v
	v = v.parent

###############################################################################

def html_output(p_board, p_whose, p_error):
	print "Here's the board: %s\nIt's %s's turn,\nerror is %s" % (p_board, p_whose, p_error)

def html_upgrade(p_board):
	print "Upgrade time: %s" % (p_board, )

def html_hexit():
	print "Hexit"

def schema_row():
	return {
		"a":0,
		"b":0,
		"c":0,
		"d":0,
		"e":0,
		"f":0,
		"g":0,
		"h":0,
	}

def fn_getRow(**kwargs):
	function_context(kwargs)
	push_context({
		"lookup": schema_row(),
	})
	if v["rank"] == 1:
		v["lookup"] = v["row1"]
	if v["rank"] == 2:
		v["lookup"] = v["row2"]
	if v["rank"] == 3:
		v["lookup"] = v["row3"]
	if v["rank"] == 4:
		v["lookup"] = v["row4"]
	if v["rank"] == 5:
		v["lookup"] = v["row5"]
	if v["rank"] == 6:
		v["lookup"] = v["row6"]
	if v["rank"] == 7:
		v["lookup"] = v["row7"]
	if v["rank"] == 8:
		v["lookup"] = v["row8"]
	toR = v["lookup"]
	pop_context()
	pop_context()
	return toR

def fn_setPiece(**kwargs):
	function_context(kwargs)
	push_context({
	})
	if v["rank"] == 1:
		if v["file"] == 1:
			v["row1"]["a"] = v["piece"]
		elif v["file"] == 2:
			v["row1"]["b"] = v["piece"]
		elif v["file"] == 3:
			v["row1"]["c"] = v["piece"]
		elif v["file"] == 4:
			v["row1"]["d"] = v["piece"]
		elif v["file"] == 5:
			v["row1"]["e"] = v["piece"]
		elif v["file"] == 6:
			v["row1"]["f"] = v["piece"]
		elif v["file"] == 7:
			v["row1"]["g"] = v["piece"]
		elif v["file"] == 8:
			v["row1"]["h"] = v["piece"]
	elif v["rank"] == 2:
		if v["file"] == 1:
			v["row2"]["a"] = v["piece"]
		elif v["file"] == 2:
			v["row2"]["b"] = v["piece"]
		elif v["file"] == 3:
			v["row2"]["c"] = v["piece"]
		elif v["file"] == 4:
			v["row2"]["d"] = v["piece"]
		elif v["file"] == 5:
			v["row2"]["e"] = v["piece"]
		elif v["file"] == 6:
			v["row2"]["f"] = v["piece"]
		elif v["file"] == 7:
			v["row2"]["g"] = v["piece"]
		elif v["file"] == 8:
			v["row2"]["h"] = v["piece"]
	elif v["rank"] == 3:
		if v["file"] == 1:
			v["row3"]["a"] = v["piece"]
		elif v["file"] == 2:
			v["row3"]["b"] = v["piece"]
		elif v["file"] == 3:
			v["row3"]["c"] = v["piece"]
		elif v["file"] == 4:
			v["row3"]["d"] = v["piece"]
		elif v["file"] == 5:
			v["row3"]["e"] = v["piece"]
		elif v["file"] == 6:
			v["row3"]["f"] = v["piece"]
		elif v["file"] == 7:
			v["row3"]["g"] = v["piece"]
		elif v["file"] == 8:
			v["row3"]["h"] = v["piece"]
	elif v["rank"] == 4:
		if v["file"] == 1:
			v["row4"]["a"] = v["piece"]
		elif v["file"] == 2:
			v["row4"]["b"] = v["piece"]
		elif v["file"] == 3:
			v["row4"]["c"] = v["piece"]
		elif v["file"] == 4:
			v["row4"]["d"] = v["piece"]
		elif v["file"] == 5:
			v["row4"]["e"] = v["piece"]
		elif v["file"] == 6:
			v["row4"]["f"] = v["piece"]
		elif v["file"] == 7:
			v["row4"]["g"] = v["piece"]
		elif v["file"] == 8:
			v["row4"]["h"] = v["piece"]
	elif v["rank"] == 5:
		if v["file"] == 1:
			v["row5"]["a"] = v["piece"]
		elif v["file"] == 2:
			v["row5"]["b"] = v["piece"]
		elif v["file"] == 3:
			v["row5"]["c"] = v["piece"]
		elif v["file"] == 4:
			v["row5"]["d"] = v["piece"]
		elif v["file"] == 5:
			v["row5"]["e"] = v["piece"]
		elif v["file"] == 6:
			v["row5"]["f"] = v["piece"]
		elif v["file"] == 7:
			v["row5"]["g"] = v["piece"]
		elif v["file"] == 8:
			v["row5"]["h"] = v["piece"]
	elif v["rank"] == 6:
		if v["file"] == 1:
			v["row6"]["a"] = v["piece"]
		elif v["file"] == 2:
			v["row6"]["b"] = v["piece"]
		elif v["file"] == 3:
			v["row6"]["c"] = v["piece"]
		elif v["file"] == 4:
			v["row6"]["d"] = v["piece"]
		elif v["file"] == 5:
			v["row6"]["e"] = v["piece"]
		elif v["file"] == 6:
			v["row6"]["f"] = v["piece"]
		elif v["file"] == 7:
			v["row6"]["g"] = v["piece"]
		elif v["file"] == 8:
			v["row6"]["h"] = v["piece"]
	elif v["rank"] == 7:
		if v["file"] == 1:
			v["row7"]["a"] = v["piece"]
		elif v["file"] == 2:
			v["row7"]["b"] = v["piece"]
		elif v["file"] == 3:
			v["row7"]["c"] = v["piece"]
		elif v["file"] == 4:
			v["row7"]["d"] = v["piece"]
		elif v["file"] == 5:
			v["row7"]["e"] = v["piece"]
		elif v["file"] == 6:
			v["row7"]["f"] = v["piece"]
		elif v["file"] == 7:
			v["row7"]["g"] = v["piece"]
		elif v["file"] == 8:
			v["row7"]["h"] = v["piece"]
	elif v["rank"] == 8:
		if v["file"] == 1:
			v["row8"]["a"] = v["piece"]
		elif v["file"] == 2:
			v["row8"]["b"] = v["piece"]
		elif v["file"] == 3:
			v["row8"]["c"] = v["piece"]
		elif v["file"] == 4:
			v["row8"]["d"] = v["piece"]
		elif v["file"] == 5:
			v["row8"]["e"] = v["piece"]
		elif v["file"] == 6:
			v["row8"]["f"] = v["piece"]
		elif v["file"] == 7:
			v["row8"]["g"] = v["piece"]
		elif v["file"] == 8:
			v["row8"]["h"] = v["piece"]
	pop_context()
	pop_context()

def fn_movePiece(**kwargs):
	function_context(kwargs)
	push_context({
		"piece":0,
		"target_piece":0
		"real_piece":0
		"dx":0,
		"dy":0,
		"lookup":schema_row(),
		"adx":0,
		"ady":0,
		"startx":0,
		"starty":0,
	})

	v["dx"] = v["to_file"] - v["from_file"]
	v["dy"] = v["to_rank"] - v["from_rank"]
	v["lookup"] = fn_getRow(v["from_rank"])
	v["piece"] = fn_getPiece(v["lookup"], v["from_file"])
	v["real_piece"] = v["piece"]
	if v["piece"] == 0:
		toR = "There is no piece at this location."
		pop_context()
		pop_context()
		return toR
	if (v["piece"] <= 6) == turn:
		toR = "You may only move your own pieces."
		pop_context()
		pop_context()
		return toR
	if v["to_rank"] != v["from_rank"]:
		v["lookup"] = fn_getRow(v["to_rank"])
	v["target_piece"] = fn_getPiece(v["lookup"], v["to_file"])
	if v["target_piece"] != 0 and (v["target_piece"] <= 6) != v["turn"]:
		toR = "You may not capture your own piece!"
		pop_context()
		pop_context()
		return toR

	if v["piece"] > 6:
		v["piece"] = v["piece"] - 6

	if v["dx"] < 0:
		v["adx"] = -v["dx"]
		v["startx"] = v["to_file"] + 1
	else:
		v["adx"] = v["dx"]
		v["startx"] = v["from_file"] + 1
	if v["dy"] < 0:
		v["ady"] = -v["dy"]
		v["starty"] = v["to_rank"] + 1
	else:
		v["ady"] = v["dy"]
		v["starty"] = v["from_rank"] + 1

	if v["piece"] == 1 or (v["piece"] == 4 and v["dx"] * v["dy"] == 0):
		push_context({
			"i":0
		})
		if (v["dx"] != 0) and (v["dy"] != 0):
			toR = "Invalid Move: Rooks move along ranks or files."
			pop_context()
			pop_context()
			return toR
		if v["dx"] != 0:
			v["i"] = v["startx"]
			v["adx"] = v["adx"] + v["i"] - 1
			while v["i"] < v["adx"]:
				if fn_getPiece(v["lookup"], v["i"]) != 0:
					toR = "Invalid Move: You may not pass other pieces."
					pop_context()
					pop_context()
					return toR
				v["i"] = v["i"] + 1
		else:
			v["i"] = v["starty"]
			v["ady"] = v["ady"] + v["i"] - 1
			while v["i"] < v["ady"]:
				if fn_getPiece(fn_getRow(v["i"]), v["to_file"]) != 0:
					return "Invalid Move: You may not pass other pieces."
				v["i"] = v["i"] + 1
	# TODO: write dis

def fn_getBoard(**kwargs):
	function_context(kwargs)
	push_context({
		"s":"",
		"i":0,
		"j":0,
		"piece":0,
		"lookup":schema_row(),
	})
	v["s"] = "<table id='game' border=0 cellspacing=0 cellpadding=0>"
	if v["pickable"]:
		v["s"] = v["s"] + "<tr><td class=from>from</td>"
		v["i"] = 1
		while v["i"] <= 8:
			v["s"] = v["s"] + "<td class=from><input onClick='set_from(" + v["i"] + ", 0);' type='radio' name='file_from' value='" + v["i"] + "'></td>"
			v["i"] = v["i"] + 1
		v["s"] = v["s"] + "<td> </td></tr>"
	v["i"] = 1
	while v["i"] <= 8:
		v["lookup"] = fn_getRow(v["i"])
		v["j"] = 1
		v["s"] = v["s"] + "<tr align=center><td class=from><input onClick='set_from(0, " + v["i"] + ");'  type='radio' name='rank_from' value='" + v["i"] + "'></td>"
		while v["j"] <= 8:
			v["piece"] = fn_getPiece(v["lookup"], v["j"])
			v["s"] = v["s"] + "<td id='r" + v["i"] + "f" + v["j"] + "'>"
			if v["piece"] != 0:
				v["s"] = v["s"] + "<img src=chess_ts/p" + v["piece"] + ".png>"
			v["s"] = v["s"] + "</td>"
			v["j"] = v["j"] + 1
		}
		if(v["pickable"])
			v["s"] = v["s"] + "<td class=to><input onClick='set_to(0, " + v["i"] + ");' type='radio' name='rank_to' value='" + v["i"] + "'></td>"
		v["s"] = v["s"] + "</tr>"
		v["i"] = v["i"] + 1
	if v["pickable"]:
		v["i"] = 1
		v["s"] = v["s"] + "<tr><td> </td>"
		while v["i"] <= 8:
			v["s"] = v["s"] + "<td class=to><input onClick='set_to(" + v["i"] + ", 0);' type='radio' name='file_to' value='" + v["i"] + "'></td>"
			v["i"] = v["i"] + 1
		v["s"] = v["s"] + "<td class=to>to</td></tr>"
	toR = v["s"] + "</table>"
	pop_context()
	pop_context()
	return toR

def session_Game():
	global admit_one
	global counter
	global v
	if counter < 1:
		push_context({"board": "", "turn_words": "", "error": "", "upgr": 0, "from_rank": 0, "from_file": 0, "to_rank": 0, "to_file": 0})
		v["error"] = ""
		v["turn"] = True
		v["row1"] = {"a":1, "b":2, "c":3, "d":4, "e":5, "f":3, "g":2, "h":1}
		v["row2"] = {"a":6, "b":6, "c":6, "d":6, "e":6, "f":6, "g":6, "h":6}
		v["row3"] = {"a":0, "b":0, "c":0, "d":0, "e":0, "f":0, "g":0, "h":0}
		v["row4"] = {"a":0, "b":0, "c":0, "d":0, "e":0, "f":0, "g":0, "h":0}
		v["row5"] = {"a":0, "b":0, "c":0, "d":0, "e":0, "f":0, "g":0, "h":0}
		v["row6"] = {"a":0, "b":0, "c":0, "d":0, "e":0, "f":0, "g":0, "h":0}
		v["row7"] = {"a":12,"b":12,"c":12,"d":12,"e":12,"f":12,"g":12,"h":12}
		v["row8"] = {"a":7, "b":8, "c":9,"d":10,"e":11, "f":9, "g":8, "h":7}

	if counter <= 2:
		if 1 <= counter <= 2:
			admit_one = True
		while admit_one or
				True:
			admit_one = False
			if counter < 1:  # counter < (show num)
				push_context({
				})
				v["board"] = fn_getBoard(True)
				if v["turn"]:
					v["turn_words"] = "White"
				else:
					v["turn_words"] = "Black"
				show(html_output, 1, p_board=v["board"], p_whose=v["turn_words"], p_error=v["error"])
			if counter == 1:  # counter == (show_num)
				v["from_rank"] = receives["rank_from"]
				v["from_file"] = receives["file_from"]
				v["to_rank"] = receives["rank_to"]
				v["to_file"] = receives["file_to"]
				counter = 0
			if counter <= 1:
				v["error"] = fn_movePiece(v["from_rank"], v["from_file"], v["to_rank"], v["to_file"])
			if counter <= 2:
				if 2 <= counter <= 2:
					admit_one = True
				if admit_one or v["error"] == "!":
					if counter < 2:
						v["board"] = fn_getBoard(False)
						show(html_upgrade, 2, p_board=v["board"])
					if counter == 2:
						v["upgr"] = receives["upg"]
						counter = 0
					if not v["turn"]:
						v["upgr"] = v["upgr"] + 6
					fn_setPiece(v["to_rank"], v["to_file"], v["upgr"])
	exit(html_hexit)

if __name__ == "__main__":
    sessions = {"Game":session_Game}
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