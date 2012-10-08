.class public TestIOlist

.super java/lang/Object

.method public <init>()V
  .limit locals 1
  .limit stack 1
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
  .limit locals 7
  .limit stack 5
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore_1
  aload_1
  ldc "Enter a list of integers, all on one line, "
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_1
  ldc "   separated by commas or spaces ... "
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_1
  invokevirtual joos/lib/JoosIO/readLine()Ljava/lang/String;
  astore 4
  new java/util/StringTokenizer
  dup
  aload 4
  ldc ", "
  iconst_0
  invokenonvirtual java/util/StringTokenizer/<init>(Ljava/lang/String;Ljava/lang/String;Z)V
  astore 6
  iconst_0
  istore_3
  start_0:
  aload 6
  invokevirtual java/util/StringTokenizer/hasMoreElements()Z
  ifeq stop_1
  iload_3
  new joos/lib/JoosString
  dup
  aload 6
  ldc ", "
  invokevirtual java/util/StringTokenizer/nextToken(Ljava/lang/String;)Ljava/lang/String;
  invokenonvirtual joos/lib/JoosString/<init>(Ljava/lang/String;)V
  invokevirtual joos/lib/JoosString/string2Int()I
  iadd
  istore_3
  goto start_0
  stop_1:
  aload_1
  ldc "The sum is: "
  new java/lang/Integer
  dup
  iload_3
  invokenonvirtual java/lang/Integer/<init>(I)V
  invokevirtual java/lang/Integer/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

