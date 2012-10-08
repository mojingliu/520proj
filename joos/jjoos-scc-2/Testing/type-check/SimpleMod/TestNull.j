.class public TestNull

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
  .limit stack 4
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore_2
  aload_2
  ldc "printing literal null: "
  ldc "null"
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  iconst_1
  ifeq else_4
  aconst_null
  astore_1
  goto stop_5
  else_4:
  new java/lang/String
  dup
  ldc "I am not null!"
  invokenonvirtual java/lang/String/<init>(Ljava/lang/String;)V
  astore_1
  stop_5:
  aload_2
  ldc "printing value null: "
  aload_1
  dup
  ifnonnull stop_9
  pop
  ldc "null"
  stop_9:
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

