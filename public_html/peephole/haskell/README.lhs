--------------------------
Haskell Pattern-C-compiler
Kamal Al-Marhubi
2007-11-20
--------------------------

Note, this is a literate Haskell document.  It should be possible to
run it with
  runhaskell README.lhs
and see the output.  With that in mind, let me just include the
pattern compiler file and a few other things that are needed.  Lines
that begin with '>' are Haskell code taht will be executed if you run
the file.

> import PatternC
> import Types
> import Args
> import Patterns

If you want to play with stuff interactively (and you are encouraged
to), you can run
  ghci README.lhs
and then you will be able to, eg, type "doIT dup_pop" to see the
aoutput from the example below get generated.

As a quick note, ghc is installed on the Trottier machines in case it
is not on the machine you are using.

This mess of code takes patterns specified in a sort-of-nice way and
generates C code that implements them.  The patterns are specified as
follows:

Pat <name> ((<bytecodes-to-match>, <list-of-conditions>) :-->: <bytecodes-to-output>)


"Pat" is essentially a keyword.  It's actually a data constructor.
The <name> is just a string that gives the name of the C function to
generate.  Lists are comma separated and enclosed in square brackets.

The <bytecodes-to-match> can contain variables, eg "ldcint x".  These
variables can be referred to in the <bytecodes-to-output>.
Additionally, if a variable occurs more than once in
<bytecodes-to-match>, the outputted C code will check for equality on
all the places it occurs.  Bytecodes can also refer to constants.  In
this case, the argument of that bytecode will be checked against the
given constant.

There is some ugliness in the way patterns are specified.  This is
because patterns are Haskell datatypes, and so certain conventions and
type restrictions prevent nicer specification.  More thought up front
could have made it possible to avoid some of these.

The C generated will also include a comment showing what the pattern
does.  Unfortunately this was not extended as more features were added
to the underlying pattern compiler.  I did not consider it a good way
to spend time.


Finally, some examples.

First a pattern with no variables or constants.  The LHS binds it to a
Haskell variable so you can call "doIT dup_pop" from ghci to see what
happens.

> dup_pop = Pat "dup_pop" (([dup, pop],[]) :-->: [])

To generate the C, pattern, there is the aptly named function "doIT".

The output from "doIT dup_pop" is:

/*
  dup 
  pop 
  ----->
  
*/
int dup_pop(CODE** c) {
  if(is_dup(*c) &&
     is_pop(next(*c))) {
    return replace_modified(c,
                            2,
                            NULL);
  }
  return 0;
}



Now a more complicated example, one with variables and constants.  This one was
implemented for us, but served as a useful sanity check early on.

> imul2 = Pat "imul2" (([ldcint x, ldcint 2, imul],[]) :-->: [ldcint x, dup, iadd])

The generated output:

/*
  ldc_int x
  ldc_int 2
  imul 
  ----->
  ldc_int x
  dup 
  iadd 
*/
int imul2(CODE** c) {
  int ints[2];
  if(is_ldc_int(*c, &(ints[0])) &&
     is_ldc_int(next(*c),
                &(ints[1])) &&
     is_imul(next(next(*c))) &&
     ints[1] == 2) {
    return replace_modified(c,
                            3,
                            makeCODEldc_int(ints[0],
                                            makeCODEdup(makeCODEiadd(NULL))));
  }
  return 0;
}


See that the argument of the first ldc is stored in ints[0], and used
afterwards.  The second ldc's argument is checked against the
constant 2.

Now, a significantly more complicated example.  This one uses
conditions to check the indegree of labels that it REDACTED.

> REDACTED = 
>     Pat "REDACTED"
>             (([REDACTED]
>             ,[Indegree x 1, Indegree y 1])
>             :-->:
>             [REDACTED])

This is one of the REDACTED cases.  The output is:

REDACTED

Go ahead and load the file and mess around.  The patterns we actually
use are specified in a list called "patterns".  See what the output
of "map doIT patterns" is.



This is the main function that gets run if you just type
  runhaskell README.lhs
at the command prompt.

> main = mapM_ (print . doIT) [dup_pop, imul2, REDACTED]