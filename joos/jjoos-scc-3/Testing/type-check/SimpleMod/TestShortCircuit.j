.class public TestShortCircuit

.super java/lang/Object

.method public <init>()V
  .limit locals 1
  .limit stack 1
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
  .limit locals 6
  .limit stack 2
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore 5
  iconst_1
  istore_1
  iconst_2
  istore_2
  iconst_3
  dup
  istore_3
  istore 4
  iload_1
  iload_2
  if_icmpeq true_3
  iconst_0
  goto stop_4
  true_3:
  iconst_1
  stop_4:
  dup
  ifne true_2
  pop
  iload_2
  iload_3
  if_icmpeq true_5
  iconst_0
  goto true_2
  true_5:
  iconst_1
  true_2:
  ifeq else_0
  aload 5
  ldc "in the first"
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  goto stop_1
  else_0:
  iload_1
  iload_2
  if_icmpeq true_9
  iconst_0
  goto stop_10
  true_9:
  iconst_1
  stop_10:
  dup
  ifne true_8
  pop
  iload_3
  iload 4
  if_icmpeq true_11
  iconst_0
  goto true_8
  true_11:
  iconst_1
  true_8:
  ifeq stop_1
  aload 5
  ldc "in the second"
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  stop_1:
  aload 5
  ldc "at the end"
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

