.class public Cons

.super java/lang/Object

.field private protected first Ljava/lang/Object;
.field private protected rest LCons;

.method public <init>(Ljava/lang/Object;LCons;)V
  .limit locals 3
  .limit stack 2
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  aload_0
  aload_1
  putfield Cons/first Ljava/lang/Object;
  aload_0
  aload_2
  putfield Cons/rest LCons;
  return
.end method

.method public setFirst(Ljava/lang/Object;)V
  .limit locals 2
  .limit stack 2
  aload_0
  aload_1
  putfield Cons/first Ljava/lang/Object;
  return
.end method

.method public member(Ljava/lang/Object;)Z
  .limit locals 2
  .limit stack 2
  aload_0
  getfield Cons/first Ljava/lang/Object;
  aload_1
  invokevirtual java/lang/Object/equals(Ljava/lang/Object;)Z
  ifeq else_0
  iconst_1
  ireturn
  else_0:
  aload_0
  getfield Cons/rest LCons;
  aconst_null
  if_acmpne else_2
  iconst_0
  ireturn
  else_2:
  aload_0
  getfield Cons/rest LCons;
  aload_1
  invokevirtual Cons/member(Ljava/lang/Object;)Z
  ireturn
.end method

.method public toString()Ljava/lang/String;
  .limit locals 1
  .limit stack 3
  aload_0
  getfield Cons/rest LCons;
  aconst_null
  if_acmpne else_0
  aload_0
  getfield Cons/first Ljava/lang/Object;
  invokevirtual java/lang/Object/toString()Ljava/lang/String;
  areturn
  else_0:
  aload_0
  getfield Cons/first Ljava/lang/Object;
  dup
  ifnull null_6
  invokevirtual java/lang/Object/toString()Ljava/lang/String;
  goto stop_7
  null_6:
  pop
  ldc "null"
  stop_7:
  ldc " "
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  dup
  ifnonnull stop_5
  pop
  ldc "null"
  stop_5:
  aload_0
  getfield Cons/rest LCons;
  dup
  ifnull null_10
  invokevirtual Cons/toString()Ljava/lang/String;
  goto stop_11
  null_10:
  pop
  ldc "null"
  stop_11:
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  areturn
.end method

