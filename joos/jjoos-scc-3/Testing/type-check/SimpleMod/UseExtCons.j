.class public UseExtCons

.super java/lang/Object

.method public <init>()V
  .limit locals 1
  .limit stack 1
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
  .limit locals 4
  .limit stack 11
  new ExtCons
  dup
  ldc "a"
  new ExtCons
  dup
  ldc "b"
  new ExtCons
  dup
  ldc "c"
  aconst_null
  iconst_3
  invokenonvirtual ExtCons/<init>(Ljava/lang/Object;LCons;I)V
  iconst_2
  invokenonvirtual ExtCons/<init>(Ljava/lang/Object;LCons;I)V
  iconst_1
  invokenonvirtual ExtCons/<init>(Ljava/lang/Object;LCons;I)V
  astore_1
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore_3
  aload_3
  ldc "a member? "
  new java/lang/Boolean
  dup
  aload_1
  ldc "a"
  invokevirtual Cons/member(Ljava/lang/Object;)Z
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_3
  ldc "z member? "
  new java/lang/Boolean
  dup
  aload_1
  ldc "z"
  invokevirtual Cons/member(Ljava/lang/Object;)Z
  invokenonvirtual java/lang/Boolean/<init>(Z)V
  invokevirtual java/lang/Boolean/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  aload_1
  invokevirtual ExtCons/printFirst()V
  aload_1
  invokevirtual ExtCons/testReturn()LCons;
  astore_2
  return
.end method

