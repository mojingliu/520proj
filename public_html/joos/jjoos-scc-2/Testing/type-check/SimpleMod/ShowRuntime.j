.class public ShowRuntime

.super java/lang/Object

.method public <init>()V
  .limit locals 1
  .limit stack 1
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  return
.end method

.method public Doit()V
  .limit locals 3
  .limit stack 4
  new java/util/Vector
  dup
  ldc 10
  iconst_1
  invokenonvirtual java/util/Vector/<init>(II)V
  astore_1
  aload_1
  iconst_0
  invokevirtual java/util/Vector/elementAt(I)Ljava/lang/Object;
  astore_2
  return
.end method

.method public static main([Ljava/lang/String;)V
  .limit locals 1
  .limit stack 2
  new ShowRuntime
  dup
  invokenonvirtual ShowRuntime/<init>()V
  invokevirtual ShowRuntime/Doit()V
  return
.end method

