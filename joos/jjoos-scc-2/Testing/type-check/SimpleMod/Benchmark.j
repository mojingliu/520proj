.class public abstract Benchmark

.super java/lang/Object

.field private protected s Ljoos/lib/JoosSystem;

.method public <init>()V
  .limit locals 1
  .limit stack 2
  aload_0
  invokenonvirtual java/lang/Object/<init>()V
  new joos/lib/JoosSystem
  dup
  invokenonvirtual joos/lib/JoosSystem/<init>()V
  aload_0
  swap
  putfield Benchmark/s Ljoos/lib/JoosSystem;
  return
.end method

.method public abstract benchmark()V
  .limit locals 1
  .limit stack 0
  return
.end method

.method public myrepeat(I)I
  .limit locals 4
  .limit stack 2
  aload_0
  getfield Benchmark/s Ljoos/lib/JoosSystem;
  invokevirtual joos/lib/JoosSystem/currentTimeMillis()I
  istore_2
  iconst_0
  istore_3
  start_0:
  iload_3
  iload_1
  if_icmpge stop_1
  aload_0
  invokevirtual Benchmark/benchmark()V
  iinc 3 1
  goto start_0
  stop_1:
  aload_0
  getfield Benchmark/s Ljoos/lib/JoosSystem;
  invokevirtual joos/lib/JoosSystem/currentTimeMillis()I
  iload_2
  isub
  ireturn
.end method

