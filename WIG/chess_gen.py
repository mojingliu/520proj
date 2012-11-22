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

counter = 0
v = VarStack(None, {"row1": schema_row(), "row2": schema_row(), "row3": schema_row(), "row4": schema_row(), "row5": schema_row(), "row6": schema_row(), "row7": schema_row(), "row8": schema_row(), "turn": False})
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
  print "(session id: %s)"% sid
  sys.exit()

def exit(html, **kwargs):
  if sid != 0:
    os.remove(sid + ".ws")
  html(**kwargs)
  sys.exit()

def save_context():
  global counter
  global v
  with open(sid + ".ws", "w") as f:
    pickle.dump((counter, v), f)

def push_context(new_context):
  global v
  v = VarStack(v, new_context)

def function_context(new_context):
  global v
  v = FnStack(v, new_context)

def pop_context():
  global v
  v = v.parent

###############################################################################

def html_output(**kwargs):
  print ("""<html><head><style>
            #game tr td
            {
                background-color:brown;
                text-align:center;
                cursor:default;
            }
            #game tr:nth-child(odd) td:nth-child(even):not(.to):not(.from), #game tr:nth-child(even) td:nth-child(odd):not(.to):not(.from)
            {
                background-color:tan;
            }
            #game tr td.from
            {
                background-color:lightblue;
            }
            #game tr td.to
            {
                background-color:yellow;
            }
        </style>
        <script>
            var to = [0, 0];
            var from = [0, 0];

            function set_one(lst, color)
            {
                return function (x, y)
                {
                    if(lst[0] != 0 && lst[1] != 0)
                        document.getElementById("r" + lst[1] + "f" + lst[0]).style.backgroundColor = (((lst[0] + lst[1]) % 2) ? "tan" : "brown");
                    lst[0] = x || lst[0];
                    lst[1] = y || lst[1];
                    if(lst[0] != 0 && lst[1] != 0)
                        document.getElementById("r" + lst[1] + "f" + lst[0]).style.backgroundColor = color;
                }
            }

            set_to = set_one(to, "yellow");
            set_from = set_one(from, "lightblue");
        </script></head><body>" + kwargs["p_board"] + "
        <span>" + kwargs["p_whose"] + "'s turn</span><br>
        <span style=\"color:red;\">" + kwargs["p_error"] + "</span>
        <span style=\"display:none\">
            <input type=\"radio\" name=file_from value=1>
            <input type=\"radio\" name=rank_from value=1>
            <input type=\"radio\" name=file_to value=1>
            <input type=\"radio\" name=rank_to value=1>
            Make WIG stop being whiny baby</span>
    </html>""")

def html_upgrade(**kwargs):
  print ("""<html><head><style>
            #game tr td
            {
                background-color:brown;
                text-align:center;
                cursor:default;
            }
            #game tr:nth-child(odd) td:nth-child(even):not(.to):not(.from), #game tr:nth-child(even) td:nth-child(odd):not(.to):not(.from)
            {
                background-color:tan;
            }
            #game tr td.from
            {
                background-color:lightblue;
            }
            #game tr td.to
            {
                background-color:yellow;
            }
        </style></head><body>" + kwargs["p_board"] + "
        <h3>Please select an upgrade for your pawn</h3>
        <input type=\"radio\" name=\"upg\" value=\"4\" checked> Queen<br>
        <input type=\"radio\" name=\"upg\" value=\"3\"> Bishop<br>
        <input type=\"radio\" name=\"upg\" value=\"2\"> Knight<br>
        <input type=\"radio\" name=\"upg\" value=\"1\"> Rook<br>
    </html>""")

def html_hexit(**kwargs):
  print ("""<html><body>But now it's dead.</body></html>""")

def schema_row():
  return {"a": 0, "b": 0, "c": 0, "d": 0, "e": 0, "f": 0, "g": 0, "h": 0}

def fn_getRow(**kwargs):
  function_context(kwargs)
  push_context({"lookup": schema_row()})
  if v["rank"] == 1:
    v["lookup"] = v["row1"]
  elif v["rank"] == 2:
    v["lookup"] = v["row2"]
  elif v["rank"] == 3:
    v["lookup"] = v["row3"]
  elif v["rank"] == 4:
    v["lookup"] = v["row4"]
  elif v["rank"] == 5:
    v["lookup"] = v["row5"]
  elif v["rank"] == 6:
    v["lookup"] = v["row6"]
  elif v["rank"] == 7:
    v["lookup"] = v["row7"]
  elif(v["rank"] == 8)
    v["lookup"] = v["row8"]
  toR = v["lookup"]
  pop_function()
  return toR
  pop_context()
  pop_function()

def fn_getPiece(**kwargs):
  function_context(kwargs)
  if(v["file"] == 1)
    toR = (v["rank"]["a"])
    pop_function()
    return toR
  if(v["file"] == 2)
    toR = (v["rank"]["b"])
    pop_function()
    return toR
  if(v["file"] == 3)
    toR = (v["rank"]["c"])
    pop_function()
    return toR
  if(v["file"] == 4)
    toR = (v["rank"]["d"])
    pop_function()
    return toR
  if(v["file"] == 5)
    toR = (v["rank"]["e"])
    pop_function()
    return toR
  if(v["file"] == 6)
    toR = (v["rank"]["f"])
    pop_function()
    return toR
  if(v["file"] == 7)
    toR = (v["rank"]["g"])
    pop_function()
    return toR
  if(v["file"] == 8)
    toR = (v["rank"]["h"])
    pop_function()
    return toR
  toR = 0
  pop_function()
  return toR
  pop_function()

def fn_setPiece(**kwargs):
  function_context(kwargs)
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
    elif(v["file"] == 8)
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
    elif(v["file"] == 8)
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
    elif(v["file"] == 8)
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
    elif(v["file"] == 8)
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
    elif(v["file"] == 8)
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
    elif(v["file"] == 8)
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
    elif(v["file"] == 8)
      v["row7"]["h"] = v["piece"]
  elif(v["rank"] == 8)
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
    elif(v["file"] == 8)
      v["row8"]["h"] = v["piece"]
  pop_function()

def fn_movePiece(**kwargs):
  function_context(kwargs)
  push_context({"piece": 0, "target_piece": 0, "real_piece": 0, "dx": 0, "dy": 0, "lookup": schema_row(), "adx": 0, "ady": 0, "startx": 0, "starty": 0})
  v["dx"] = v["to_file"] - v["from_file"]
  v["dy"] = v["to_rank"] - v["from_rank"]
  v["lookup"] = fn_getRow(v["from_rank"])
  v["piece"] = fn_getPiece(v["lookup"], v["from_file"])
  v["real_piece"] = v["piece"]
  if(v["piece"] == 0)
    toR = "There is no piece at this location."
    pop_function()
    return toR
  if((v["piece"] <= 6) == v["turn"])
    toR = "You may only move your own pieces."
    pop_function()
    return toR
  if(v["to_rank"] != v["from_rank"])
    v["lookup"] = fn_getRow(v["to_rank"])
  v["target_piece"] = fn_getPiece(v["lookup"], v["to_file"])
  if(v["target_piece"] != 0 and (v["target_piece"] <= 6) != v["turn"])
    toR = "You may not capture your own piece!"
    pop_function()
    return toR
  if(v["piece"] > 6)
    v["piece"] = v["piece"] - 6
  if v["dx"] < 0:
    v["adx"] = 0 - v["dx"]
    v["startx"] = v["to_file"] + 1
  else:
    v["adx"] = v["dx"]
    v["startx"] = v["from_file"] + 1
  if v["dy"] < 0:
    v["ady"] = 0 - v["dy"]
    v["starty"] = v["to_rank"] + 1
  else:
    v["ady"] = v["dy"]
    v["starty"] = v["from_rank"] + 1
  if v["piece"] == 1 or (v["piece"] == 4 and v["dx"] * v["dy"] == 0):
    push_context({"i": 0})
    if((v["dx"] != 0) and (v["dy"] != 0))
      toR = "Invalid Move: Rooks move along ranks or files."
      pop_function()
      return toR
    if v["dx"] != 0:
      v["i"] = v["startx"]
      v["adx"] = v["adx"] + v["i"] - 1
      while v["i"] < v["adx"]:
        if(fn_getPiece(v["lookup"], v["i"]) != 0)
          toR = "Invalid Move: You may not pass other pieces."
          pop_function()
          return toR
        v["i"] = v["i"] + 1
    else:
      v["i"] = v["starty"]
      v["ady"] = v["ady"] + v["i"] - 1
      while v["i"] < v["ady"]:
        if(fn_getPiece(fn_getRow(v["i"]), v["to_file"]) != 0)
          toR = "Invalid Move: You may not pass other pieces."
          pop_function()
          return toR
        v["i"] = v["i"] + 1
    pop_context()
  elif v["piece"] == 2:
    if(v["adx"] * v["ady"] != 2)
      toR = "Invalid Move: Knights may only move in an L shape."
      pop_function()
      return toR
  elif v["piece"] == 3 or v["piece"] == 4:
    push_context({"i": 0})
    v["i"] = 0
    if v["dx"] == v["dy"]:
      while v["i"] < v["adx"] - 1:
        if(fn_getPiece(fn_getRow(v["starty"] + v["i"]), v["startx"] + v["i"]) != 0)
          toR = "Invalid Move: You may not pass other pieces."
          pop_function()
          return toR
        v["i"] = v["i"] + 1
    elif v["adx"] == v["ady"]:
      while v["i"] < v["adx"] - 1:
        if(fn_getPiece(fn_getRow(v["starty"] + v["i"]), v["startx"] + (v["ady"] - 2) - v["i"]) != 0)
          toR = "Invalid Move: You may not pass other pieces."
          pop_function()
          return toR
        v["i"] = v["i"] + 1
    else:
      if(v["piece"] == 4)
        toR = "Invalid Move: Queens may only move along ranks, files, or diagonally."
        pop_function()
        return toR
      toR = "Invalid Move: Bishops may only move diagonally."
      pop_function()
      return toR
    pop_context()
  elif v["piece"] == 5:
    if(not ((v["adx"] == 1 or v["ady"] == 1) and v["adx"] + v["ady"] <= 2))
      toR = "Invalid Move: Kings may only move one square."
      pop_function()
      return toR
  elif v["piece"] == 6:
    if(v["dy"] == 0)
      toR = "Invalid Move: Pawns don't move sideways ever."
      pop_function()
      return toR
    if((v["dy"] < 0) != v["turn"])
      toR = "Invalid Move: Pawns may not retreat."
      pop_function()
      return toR
    if v["adx"] == 1:
      if v["ady"] == 1:
        if(v["target_piece"] == 0)
          toR = "Invalid Move: Pawns may only capture diagonally."
          pop_function()
          return toR
      else:
        toR = "Invalid Move: Pawns don't move that quickly."
        pop_function()
        return toR
    elif v["adx"] == 0:
      if v["target_piece"] != 0:
        toR = "Invalid Move: Pawns may only capture diagonally."
        pop_function()
        return toR
      elif v["ady"] == 2 and (v["from_rank"] == 2 or v["from_rank"] == 7):
        if(fn_getPiece(fn_getRow(v["from_rank"] + v["dy"] // 2), v["from_file"]) != 0)
          toR = "Invalid Move: You may not pass other pieces."
          pop_function()
          return toR
      elif(v["ady"] != 1)
        toR = "Invalid Move: Pawns don't move that quickly."
        pop_function()
        return toR
    else:
      toR = "Invalid Move: Pawns don't move that quickly."
      pop_function()
      return toR
  else:
    toR = "Error: how did you even get this piece???"
    pop_function()
    return toR
  fn_setPiece(v["from_rank"], v["from_file"], 0)
  fn_setPiece(v["to_rank"], v["to_file"], v["real_piece"])
  v["turn"] = not v["turn"]
  if(v["piece"] == 6 and (v["to_rank"] == 8 or v["to_rank"] == 1))
    toR = "!"
    pop_function()
    return toR
  toR = ""
  pop_function()
  return toR
  pop_context()
  pop_function()

def fn_getBoard(**kwargs):
  function_context(kwargs)
  push_context({"s": "", "i": 0, "j": 0, "piece": 0, "lookup": schema_row()})
  v["s"] = "<table id='game' border=0 cellspacing=0 cellpadding=0>"
  if(v["pickable"])
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
      if(v["piece"] != 0)
        v["s"] = v["s"] + "<img src=chess_ts/p" + v["piece"] + ".png>"
      v["s"] = v["s"] + "</td>"
      v["j"] = v["j"] + 1
    if(v["pickable"])
      v["s"] = v["s"] + "<td class=to><input onClick='set_to(0, " + v["i"] + ");' type='radio' name='rank_to' value='" + v["i"] + "'></td>"
    v["s"] = v["s"] + "</tr>"
    v["i"] = v["i"] + 1
  if(v["pickable"])
    v["i"] = 1
    v["s"] = v["s"] + "<tr><td> </td>"
    while v["i"] <= 8:
      v["s"] = v["s"] + "<td class=to><input onClick='set_to(" + v["i"] + ", 0);' type='radio' name='file_to' value='" + v["i"] + "'></td>"
      v["i"] = v["i"] + 1
    v["s"] = v["s"] + "<td class=to>to</td></tr>"
  toR = v["s"] + "</table>"
  pop_function()
  return toR
  pop_context()
  pop_function()

def session_Game():
  global counter
  global v
  admit_one = False
  push_context({"board": "", "turn_words": "", "error": "", "upgr": 0, "from_rank": 0, "from_file": 0, "to_rank": 0, "to_file": 0})
  v["error"] = ""
  v["turn"] = True
  v["row1"] = {"a": 1, "b": 2, "c": 3, "d": 4, "e": 5, "f": 3, "g": 2, "h": 1}
  v["row2"] = {"a": 6, "b": 6, "c": 6, "d": 6, "e": 6, "f": 6, "g": 6, "h": 6}
  v["row3"] = {"a": 0, "b": 0, "c": 0, "d": 0, "e": 0, "f": 0, "g": 0, "h": 0}
  v["row4"] = {"a": 0, "b": 0, "c": 0, "d": 0, "e": 0, "f": 0, "g": 0, "h": 0}
  v["row5"] = {"a": 0, "b": 0, "c": 0, "d": 0, "e": 0, "f": 0, "g": 0, "h": 0}
  v["row6"] = {"a": 0, "b": 0, "c": 0, "d": 0, "e": 0, "f": 0, "g": 0, "h": 0}
  v["row7"] = {"a": 12, "b": 12, "c": 12, "d": 12, "e": 12, "f": 12, "g": 12, "h": 12}
  v["row8"] = {"a": 7, "b": 8, "c": 9, "d": 10, "e": 11, "f": 9, "g": 8, "h": 7}
  while True:
    v["board"] = fn_getBoard(True)
    if v["turn"]:
      v["turn_words"] = "White"
    else:
      v["turn_words"] = "Black"
    show(html_output, 1, p_error=v["error"], p_whose=v["turn_words"], p_board=v["board"])
    if counter == 1:
      v["from_rank"] = receives["rank_from"]
      v["from_file"] = receives["file_from"]
      v["to_rank"] = receives["rank_to"]
      v["to_file"] = receives["file_to"]
      counter = 0
    v["error"] = fn_movePiece(v["from_rank"], v["from_file"], v["to_rank"], v["to_file"])
    if(v["error"] == "!")
      v["board"] = fn_getBoard(False)
      show(html_upgrade, 2, p_board=v["board"])
      if counter == 2:
        v["upgr"] = receives["upg"]
        counter = 0
      if(not v["turn"])
        v["upgr"] = v["upgr"] + 6
      fn_setPiece(v["to_rank"], v["to_file"], v["upgr"])
  exit(html_hexit, 3)
  pop_context()

