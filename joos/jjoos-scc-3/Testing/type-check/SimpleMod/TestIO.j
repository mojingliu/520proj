.class public TestIO

.super java/lang/Object

.method public <init>()V
  .limit locals 1
  .limit stack 1
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
  .limit locals 5
  .limit stack 4
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore_1
  aload_1
  ldc "Hello World"
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_1
  ldc "Enter a string: "
  invokevirtual joos/lib/JoosIO/print(Ljava/lang/String;)V
  aload_1
  invokevirtual joos/lib/JoosIO/readLine()Ljava/lang/String;
  astore 4
  aload_1
  ldc "The string s is: "
  invokevirtual joos/lib/JoosIO/print(Ljava/lang/String;)V
  aload_1
  aload 4
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_1
  ldc "Enter an integer: "
  invokevirtual joos/lib/JoosIO/print(Ljava/lang/String;)V
  aload_1
  invokevirtual joos/lib/JoosIO/readInt()I
  istore_3
  aload_1
  ldc "The integer i is: "
  invokevirtual joos/lib/JoosIO/print(Ljava/lang/String;)V
  aload_1
  new java/lang/Integer
  dup
  iload_3
  invokenonvirtual java/lang/Integer/<init>(I)V
  invokevirtual java/lang/Integer/toString()Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_1
  ldc "Enter a boolean: "
  invokevirtual joos/lib/JoosIO/print(Ljava/lang/String;)V
  aload_1
  invokevirtual joos/lib/JoosIO/readBoolean()Z
  istore_2
  aload_1
  ldc "The boolean b is: "
  invokevirtual joos/lib/JoosIO/print(Ljava/lang/String;)V
  aload_1
  new java/lang/Boolean
  dup
  iload_2
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

