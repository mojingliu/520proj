.class public TestString

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
  .limit stack 3
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore 4
  new joos/lib/JoosString
  dup
  ldc "true"
  invokenonvirtual joos/lib/JoosString/<init>(Ljava/lang/String;)V
  astore_1
  aload_1
  invokevirtual joos/lib/JoosString/string2Bool()Z
  ifeq stop_0
  aload 4
  ldc "string2Bool is ok"
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  stop_0:
  new joos/lib/JoosString
  dup
  ldc "10"
  invokenonvirtual joos/lib/JoosString/<init>(Ljava/lang/String;)V
  astore_2
  aload_2
  invokevirtual joos/lib/JoosString/string2Int()I
  ldc 10
  if_icmpne stop_1
  aload 4
  ldc "string2Int is ok"
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  stop_1:
  new joos/lib/JoosString
  dup
  ldc "I am a string"
  invokenonvirtual joos/lib/JoosString/<init>(Ljava/lang/String;)V
  astore_3
  aload_3
  invokevirtual joos/lib/JoosString/valueOf()Ljava/lang/String;
  ldc "I am a string"
  if_acmpne stop_4
  aload 4
  ldc "valueOf is ok"
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  stop_4:
  return
.end method

