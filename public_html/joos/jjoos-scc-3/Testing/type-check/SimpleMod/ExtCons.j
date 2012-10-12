.class public ExtCons

.super Cons

.field private protected intField I

.method public <init>(Ljava/lang/Object;LCons;I)V
  .limit locals 4
  .limit stack 3
  aload_0
  aload_1
  aload_2
  invokenonvirtual Cons/<init>(Ljava/lang/Object;LCons;)V
  aload_0
  iload_3
  putfield ExtCons/intField I
  return
.end method

.method public setIntField(I)V
  .limit locals 2
  .limit stack 2
  aload_0
  iload_1
  putfield ExtCons/intField I
  return
.end method

.method public setFirst(Ljava/lang/Object;)V
  .limit locals 3
  .limit stack 2
  new java/lang/Object
  dup
  invokenonvirtual java/lang/Object/<init>()V
  astore_2
  aload_0
  aload_2
  invokenonvirtual Cons/setFirst(Ljava/lang/Object;)V
  return
.end method

.method public testReturn()LCons;
  .limit locals 1
  .limit stack 5
  new ExtCons
  dup
  ldc "abc"
  aconst_null
  iconst_3
  invokenonvirtual ExtCons/<init>(Ljava/lang/Object;LCons;I)V
  areturn
.end method

.method public testLookup(LCons;Ljava/lang/Object;)V
  .limit locals 3
  .limit stack 2
  aload_1
  aload_2
  invokevirtual Cons/setFirst(Ljava/lang/Object;)V
  return
.end method

.method public testSuper(Ljava/lang/Object;)V
  .limit locals 2
  .limit stack 2
  aload_0
  aload_1
  invokenonvirtual Cons/setFirst(Ljava/lang/Object;)V
  return
.end method

.method public printFirst()V
  .limit locals 1
  .limit stack 4
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  ldc "first is: "
  aload_0
  getfield Cons/first Ljava/lang/Object;
  dup
  ifnull null_2
  invokevirtual java/lang/Object/toString()Ljava/lang/String;
  goto stop_3
  null_2:
  pop
  ldc "null"
  stop_3:
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

