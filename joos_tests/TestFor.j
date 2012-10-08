.class public final TestFor

.super java/lang/Object

.method public <init>()V
  .limit locals 1
  .limit stack 25
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
  .limit locals 10
  .limit stack 25
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  dup
  astore 8
  pop
  iconst_0
  dup
  istore 9
  pop
  iload 9
  iconst_1
  iadd
  dup
  istore 9
  pop
  aload 8
  ldc "Wowie++!!! "
  dup
  ifnull null_2
  goto stop_3
  null_2:
  pop
  ldc "null"
  stop_3:
  new java/lang/Integer
  dup
  iload 9
  iconst_1
  iadd
  dup
  istore 9
  invokenonvirtual java/lang/Integer/<init>(I)V
  invokevirtual java/lang/Integer/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  dup
  ifnull null_0
  goto stop_1
  null_0:
  pop
  ldc "null"
  stop_1:
  ldc " == 1"
  dup
  ifnull null_6
  goto stop_7
  null_6:
  pop
  ldc "null"
  stop_7:
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  iload 9
  ldc 50
  iadd
  dup
  istore 9
  pop
  aload 8
  ldc "Kazowie+=!!! "
  dup
  ifnull null_10
  goto stop_11
  null_10:
  pop
  ldc "null"
  stop_11:
  new java/lang/Integer
  dup
  iload 9
  ldc 50
  iadd
  dup
  istore 9
  invokenonvirtual java/lang/Integer/<init>(I)V
  invokevirtual java/lang/Integer/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  dup
  ifnull null_8
  goto stop_9
  null_8:
  pop
  ldc "null"
  stop_9:
  ldc " == 102"
  dup
  ifnull null_14
  goto stop_15
  null_14:
  pop
  ldc "null"
  stop_15:
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

