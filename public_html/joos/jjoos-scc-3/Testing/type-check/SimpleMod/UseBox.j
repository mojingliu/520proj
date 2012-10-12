.class public UseBox

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
  .limit stack 2
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore_2
  new SyncBox
  dup
  invokenonvirtual SyncBox/<init>()V
  astore_1
  aload_1
  ldc "abc"
  invokevirtual SyncBox/put(Ljava/lang/Object;)Z
  pop
  aload_2
  aload_1
  invokevirtual SyncBox/get()Ljava/lang/Object;
  invokevirtual java/lang/Object/toString()Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

