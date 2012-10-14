.class public final TestEqual

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
  .limit stack 5
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  dup
  astore 8
  pop
  new java/lang/Object
  dup
  invokenonvirtual java/lang/Object/<init>()V
  dup
  astore_1
  pop
  new java/lang/Object
  dup
  invokenonvirtual java/lang/Object/<init>()V
  dup
  astore_2
  pop
  aload_1
  aload_2
  if_acmpeq true_0
  iconst_0
  goto stop_1
  true_0:
  iconst_1
  stop_1:
  dup
  istore 4
  pop
  aload 8
  ldc "b1 should be false: "
  dup
  ifnull null_2
  goto stop_3
  null_2:
  pop
  ldc "null"
  stop_3:
  new java/lang/Boolean
  dup
  iload 4
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  iload 4
  ifeq true_6
  iconst_0
  goto stop_7
  true_6:
  iconst_1
  stop_7:
  dup
  istore 5
  dup
  istore 6
  pop
  aload 8
  ldc "b2 and b3 should be true: "
  dup
  ifnull null_12
  goto stop_13
  null_12:
  pop
  ldc "null"
  stop_13:
  new java/lang/Boolean
  dup
  iload 5
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  dup
  ifnull null_10
  goto stop_11
  null_10:
  pop
  ldc "null"
  stop_11:
  ldc " "
  dup
  ifnull null_16
  goto stop_17
  null_16:
  pop
  ldc "null"
  stop_17:
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  dup
  ifnull null_8
  goto stop_9
  null_8:
  pop
  ldc "null"
  stop_9:
  new java/lang/Boolean
  dup
  iload 6
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  ldc "hi"
  dup
  astore 7
  pop
  aload 7
  invokevirtual java/lang/String/length()I
  dup
  istore_3
  pop
  iload_3
  aload 7
  invokevirtual java/lang/String/length()I
  if_icmpeq true_20
  iconst_0
  goto stop_21
  true_20:
  iconst_1
  stop_21:
  dup
  istore 6
  pop
  aload 8
  ldc "b3 should be true: "
  dup
  ifnull null_22
  goto stop_23
  null_22:
  pop
  ldc "null"
  stop_23:
  new java/lang/Boolean
  dup
  iload 6
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

