.class public StrCat

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
  .limit stack 4
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore 6
  ldc " Hello World "
  astore_1
  aload_1
  dup
  ifnonnull stop_1
  pop
  ldc "null"
  stop_1:
  new java/lang/Integer
  dup
  ldc 10
  invokenonvirtual java/lang/Integer/<init>(I)V
  invokevirtual java/lang/Integer/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  astore_2
  aload 6
  aload_2
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload 6
  dup
  ifnull null_4
  invokevirtual java/lang/Object/toString()Ljava/lang/String;
  goto stop_5
  null_4:
  pop
  ldc "null"
  stop_5:
  aload_1
  dup
  ifnonnull stop_7
  pop
  ldc "null"
  stop_7:
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  astore_3
  aload 6
  aload_3
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  new java/lang/String
  dup
  aload_1
  invokevirtual java/lang/String/toString()Ljava/lang/String;
  invokenonvirtual java/lang/String/<init>(Ljava/lang/String;)V
  new java/lang/Integer
  dup
  ldc 10
  invokenonvirtual java/lang/Integer/<init>(I)V
  invokevirtual java/lang/Integer/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  astore 4
  aload 6
  aload 4
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  new java/lang/String
  dup
  aload 6
  invokevirtual java/lang/Object/toString()Ljava/lang/String;
  invokenonvirtual java/lang/String/<init>(Ljava/lang/String;)V
  aload_1
  invokevirtual java/lang/String/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  astore 5
  aload 6
  aload 5
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

