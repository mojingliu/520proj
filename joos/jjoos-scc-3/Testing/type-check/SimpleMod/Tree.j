.class public Tree

.super java/lang/Object

.field private protected value Ljava/lang/Object;
.field private protected left LTree;
.field private protected right LTree;

.method public <init>(Ljava/lang/Object;LTree;LTree;)V
  .limit locals 4
  .limit stack 2
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  aload_0
  aload_1
  putfield Tree/value Ljava/lang/Object;
  aload_0
  aload_2
  putfield Tree/left LTree;
  aload_0
  aload_3
  putfield Tree/right LTree;
  return
.end method

.method public setValue(Ljava/lang/Object;)V
  .limit locals 2
  .limit stack 2
  aload_0
  aload_1
  putfield Tree/value Ljava/lang/Object;
  return
.end method

