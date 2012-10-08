.class public TestComp

.super java/lang/Object

.method public <init>()V
  .limit locals 1
  .limit stack 1
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
  .limit locals 9
  .limit stack 6
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore_1
  aload_1
  ldc "(true) equality on bools:"
  new java/lang/Boolean
  dup
  iconst_1
  iconst_1
  if_icmpeq true_4
  iconst_0
  goto stop_5
  true_4:
  iconst_1
  stop_5:
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_1
  ldc "(true) equality on ints:"
  new java/lang/Boolean
  dup
  iconst_3
  iconst_3
  if_icmpeq true_10
  iconst_0
  goto stop_11
  true_10:
  iconst_1
  stop_11:
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  new Cons
  dup
  ldc "cons"
  aconst_null
  invokenonvirtual Cons/<init>(Ljava/lang/Object;LCons;)V
  astore_2
  new Cons
  dup
  ldc "cons"
  aconst_null
  invokenonvirtual Cons/<init>(Ljava/lang/Object;LCons;)V
  astore_3
  aload_1
  ldc "(true) equality of refs to same ref: "
  new java/lang/Boolean
  dup
  aload_2
  aload_2
  if_acmpeq true_16
  iconst_0
  goto stop_17
  true_16:
  iconst_1
  stop_17:
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_1
  ldc "(false)equality of refs to same type: "
  new java/lang/Boolean
  dup
  aload_2
  aload_3
  if_acmpeq true_22
  iconst_0
  goto stop_23
  true_22:
  iconst_1
  stop_23:
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  new ExtCons
  dup
  ldc "cons"
  aconst_null
  iconst_0
  invokenonvirtual ExtCons/<init>(Ljava/lang/Object;LCons;I)V
  astore 5
  aload_1
  ldc "(false )equality of refs to subclass: "
  new java/lang/Boolean
  dup
  aload_2
  aload 5
  if_acmpeq true_28
  iconst_0
  goto stop_29
  true_28:
  iconst_1
  stop_29:
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  new java/lang/String
  dup
  ldc "I am a string"
  invokenonvirtual java/lang/String/<init>(Ljava/lang/String;)V
  astore 7
  iconst_3
  istore 8
  new Tree
  dup
  new java/lang/Integer
  dup
  iconst_1
  invokenonvirtual java/lang/Integer/<init>(I)V
  aconst_null
  aconst_null
  invokenonvirtual Tree/<init>(Ljava/lang/Object;LTree;LTree;)V
  astore 4
  aload_1
  ldc "(true) instanceof on subtypes: "
  new java/lang/Boolean
  dup
  aload 5
  invokevirtual ExtCons/testReturn()LCons;
  instanceof ExtCons
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload 5
  invokevirtual ExtCons/testReturn()LCons;
  checkcast ExtCons
  astore 6
  aload 6
  checkcast Cons
  astore_2
  aload_3
  checkcast Cons
  astore_2
  return
.end method

