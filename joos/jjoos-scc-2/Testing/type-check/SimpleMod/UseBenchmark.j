.class public UseBenchmark

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
  .limit stack 5
  new ExtBenchmark
  dup
  invokenonvirtual ExtBenchmark/<init>()V
  astore_1
  new joos/lib/JoosIO
  dup
  invokenonvirtual joos/lib/JoosIO/<init>()V
  astore_2
  aload_2
  ldc "Enter number of repetitions: "
  invokevirtual joos/lib/JoosIO/print(Ljava/lang/String;)V
  aload_2
  invokevirtual joos/lib/JoosIO/readInt()I
  istore_3
  aload_1
  iload_3
  invokevirtual Benchmark/myrepeat(I)I
  istore 4
  aload_2
  ldc "time is "
  new java/lang/Integer
  dup
  iload 4
  invokenonvirtual java/lang/Integer/<init>(I)V
  invokevirtual java/lang/Integer/toString()Ljava/lang/String;
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  dup
  ifnonnull stop_1
  pop
  ldc "null"
  stop_1:
  ldc " millisecs"
  invokevirtual java/lang/String/concat(Ljava/lang/String;)Ljava/lang/String;
  invokevirtual joos/lib/JoosIO/println(Ljava/lang/String;)V
  return
.end method

