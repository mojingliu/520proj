.class public UseCons

.super java/lang/Object

.method public <init>()V
  .limit locals 1
  .limit stack 1
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
  .limit locals 3
  .limit stack 10
  new Cons
  dup
  ldc "a"
  new Cons
  dup
  ldc "b"
  new Cons
  dup
  ldc "c"
  aconst_null
  invokenonvirtual Cons/<init>(Ljava/lang/Object;LCons;)V
  invokenonvirtual Cons/<init>(Ljava/lang/Object;LCons;)V
  invokenonvirtual Cons/<init>(Ljava/lang/Object;LCons;)V
  astore_1
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore_2
  aload_2
  aload_1
  invokevirtual Cons/toString()Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_2
  ldc "a member? "
  new java/lang/Boolean
  dup
  aload_1
  ldc "a"
  invokevirtual Cons/member(Ljava/lang/Object;)Z
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_2
  ldc "z member? "
  new java/lang/Boolean
  dup
  aload_1
  ldc "z"
  invokevirtual Cons/member(Ljava/lang/Object;)Z
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

