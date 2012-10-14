.class public SyncBox

.super java/lang/Object

.field private protected boxContents Ljava/lang/Object;

.method public <init>()V
  .limit locals 1
  .limit stack 1
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  return
.end method

.method public synchronized get()Ljava/lang/Object;
  .limit locals 2
  .limit stack 2
  aload_0
  getfield SyncBox/boxContents Ljava/lang/Object;
  astore_1
  aload_0
  aconst_null
  putfield SyncBox/boxContents Ljava/lang/Object;
  aload_1
  areturn
.end method

.method public synchronized put(Ljava/lang/Object;)Z
  .limit locals 2
  .limit stack 2
  aload_0
  getfield SyncBox/boxContents Ljava/lang/Object;
  aconst_null
  if_acmpeq stop_0
  iconst_0
  ireturn
  stop_0:
  aload_0
  aload_1
  putfield SyncBox/boxContents Ljava/lang/Object;
  iconst_1
  ireturn
.end method

