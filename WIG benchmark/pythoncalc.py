#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import cgi, cgitb
form = cgi.FieldStorage()
operator = form.getvalue('operator')
int1 = form.getvalue('int1')
int2 = form.getvalue('int2')

print "Content-type:text/html\r\n\r\n"
print "<html>"
print "<body>"
print "<h1> A Simple Calculator </h1>"
print "<form action='pythoncalc.py' method='get'>"
print "<p> Enter your operator (+ or -):"
print "<input type ='text' name ='operator' maxlength='1' size = 1/>"
print "<p> Enter the first number (-99 to 999):"
print "<input type ='text' name = 'int1' maxlength='3' size = 3/>"
print "<p> Enter the second number (-99 to 999):"
print "<input type='text' name='int2' maxlength='3' size=3/>"
print "<input type='submit' value='Submit'/>"
print "</form>"
print 
if (int1 == None) or (int2 == None) or (operator == None):
    print "No results yet!  Please fill in all fields and hit submit."
else:
    if operator == "+":
        print "Result = " + str(int(int1) + int(int2))
    elif operator == "-":
        print "Result = " + str(int(int1) - int(int2))
    else:
        print "You need a + or - for the operator!"

print "</body>"
print "</html>"
