; ModuleID = 'loop_test.bc'
source_filename = "test_api_1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.test_structure_1 = type { i32, i32, i32* }

@.str = private unnamed_addr constant [11 x i8] c"test_ptr_1\00", align 1
@.str.1 = private unnamed_addr constant [2 x i8] c"b\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !7 {
entry:
  %test_ptr_1 = alloca %struct.test_structure_1*, align 8
  %b = alloca i32, align 4
  call void @llvm.dbg.declare(metadata %struct.test_structure_1** %test_ptr_1, metadata !11, metadata !DIExpression()), !dbg !21
  call void @llvm.dbg.declare(metadata i32* %b, metadata !22, metadata !DIExpression()), !dbg !23
  %call = call i32 (%struct.test_structure_1**, i64, i8*, i32, ...) bitcast (i32 (...)* @klee_make_symbolic_controllable to i32 (%struct.test_structure_1**, i64, i8*, i32, ...)*)(%struct.test_structure_1** %test_ptr_1, i64 8, i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str, i64 0, i64 0), i32 1), !dbg !24
  %call1 = call i32 (i32*, i64, i8*, i32, ...) bitcast (i32 (...)* @klee_make_symbolic_controllable to i32 (i32*, i64, i8*, i32, ...)*)(i32* %b, i64 4, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.1, i64 0, i64 0), i32 1), !dbg !25
  %0 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1, align 8, !dbg !26
  %1 = load i32, i32* %b, align 4, !dbg !27
  call void @test_api_1(%struct.test_structure_1* %0, i32 %1), !dbg !28
  ret i32 0, !dbg !29
}

; Function Attrs: nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare dso_local i32 @klee_make_symbolic_controllable(...) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @test_api_1(%struct.test_structure_1* %test_ptr_1, i32 %b) #0 !dbg !30 {
entry:
  %test_ptr_1.addr = alloca %struct.test_structure_1*, align 8
  %b.addr = alloca i32, align 4
  store %struct.test_structure_1* %test_ptr_1, %struct.test_structure_1** %test_ptr_1.addr, align 8
  call void @llvm.dbg.declare(metadata %struct.test_structure_1** %test_ptr_1.addr, metadata !33, metadata !DIExpression()), !dbg !34
  store i32 %b, i32* %b.addr, align 4
  call void @llvm.dbg.declare(metadata i32* %b.addr, metadata !35, metadata !DIExpression()), !dbg !36
  br label %while.cond, !dbg !37

while.cond:                                       ; preds = %while.body, %entry
  %0 = load i32, i32* %b.addr, align 4, !dbg !38
  %dec = add nsw i32 %0, -1, !dbg !38
  store i32 %dec, i32* %b.addr, align 4, !dbg !38
  %tobool = icmp ne i32 %0, 0, !dbg !37
  br i1 %tobool, label %while.body, label %while.end, !dbg !37

while.body:                                       ; preds = %while.cond
  %1 = load i32, i32* %b.addr, align 4, !dbg !39
  %2 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !41
  %b1 = getelementptr inbounds %struct.test_structure_1, %struct.test_structure_1* %2, i32 0, i32 1, !dbg !42
  store i32 %1, i32* %b1, align 4, !dbg !43
  br label %while.cond, !dbg !37, !llvm.loop !44

while.end:                                        ; preds = %while.cond
  %3 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !46
  %cmp = icmp ugt %struct.test_structure_1* %3, inttoptr (i64 2415919103 to %struct.test_structure_1*), !dbg !48
  br i1 %cmp, label %if.then, label %lor.lhs.false, !dbg !49

lor.lhs.false:                                    ; preds = %while.end
  %4 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !50
  %cmp2 = icmp ult %struct.test_structure_1* %4, inttoptr (i64 2147483648 to %struct.test_structure_1*), !dbg !51
  br i1 %cmp2, label %if.then, label %if.end6, !dbg !52

if.then:                                          ; preds = %lor.lhs.false, %while.end
  %5 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !53
  %a = getelementptr inbounds %struct.test_structure_1, %struct.test_structure_1* %5, i32 0, i32 0, !dbg !56
  %6 = load i32, i32* %a, align 8, !dbg !56
  %cmp3 = icmp eq i32 %6, 0, !dbg !57
  br i1 %cmp3, label %if.then4, label %if.end, !dbg !58

if.then4:                                         ; preds = %if.then
  %7 = load i32, i32* %b.addr, align 4, !dbg !59
  %8 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !61
  %b5 = getelementptr inbounds %struct.test_structure_1, %struct.test_structure_1* %8, i32 0, i32 1, !dbg !62
  store i32 %7, i32* %b5, align 4, !dbg !63
  br label %if.end, !dbg !64

if.end:                                           ; preds = %if.then4, %if.then
  br label %if.end6, !dbg !65

if.end6:                                          ; preds = %if.end, %lor.lhs.false
  ret void, !dbg !66
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone speculatable willreturn }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5}
!llvm.ident = !{!6}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 11.0.0 (https://github.com/llvm/llvm-project.git 60a25202a7dd1e00067fcfce512086ebf3788537)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "test_api_1.c", directory: "/home/klee/klee_test/test_files")
!2 = !{}
!3 = !{i32 7, !"Dwarf Version", i32 4}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 4}
!6 = !{!"clang version 11.0.0 (https://github.com/llvm/llvm-project.git 60a25202a7dd1e00067fcfce512086ebf3788537)"}
!7 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 9, type: !8, scopeLine: 9, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!8 = !DISubroutineType(types: !9)
!9 = !{!10}
!10 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!11 = !DILocalVariable(name: "test_ptr_1", scope: !7, file: !1, line: 10, type: !12)
!12 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !13, size: 64)
!13 = !DIDerivedType(tag: DW_TAG_typedef, name: "test_structure_1_t", file: !14, line: 10, baseType: !15)
!14 = !DIFile(filename: "./test_api.h", directory: "/home/klee/klee_test/test_files")
!15 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "test_structure_1", file: !14, line: 6, size: 128, elements: !16)
!16 = !{!17, !18, !19}
!17 = !DIDerivedType(tag: DW_TAG_member, name: "a", scope: !15, file: !14, line: 7, baseType: !10, size: 32)
!18 = !DIDerivedType(tag: DW_TAG_member, name: "b", scope: !15, file: !14, line: 8, baseType: !10, size: 32, offset: 32)
!19 = !DIDerivedType(tag: DW_TAG_member, name: "p", scope: !15, file: !14, line: 9, baseType: !20, size: 64, offset: 64)
!20 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !10, size: 64)
!21 = !DILocation(line: 10, column: 27, scope: !7)
!22 = !DILocalVariable(name: "b", scope: !7, file: !1, line: 11, type: !10)
!23 = !DILocation(line: 11, column: 9, scope: !7)
!24 = !DILocation(line: 12, column: 5, scope: !7)
!25 = !DILocation(line: 13, column: 5, scope: !7)
!26 = !DILocation(line: 14, column: 16, scope: !7)
!27 = !DILocation(line: 14, column: 27, scope: !7)
!28 = !DILocation(line: 14, column: 5, scope: !7)
!29 = !DILocation(line: 15, column: 1, scope: !7)
!30 = distinct !DISubprogram(name: "test_api_1", scope: !1, file: !1, line: 17, type: !31, scopeLine: 17, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!31 = !DISubroutineType(types: !32)
!32 = !{null, !12, !10}
!33 = !DILocalVariable(name: "test_ptr_1", arg: 1, scope: !30, file: !1, line: 17, type: !12)
!34 = !DILocation(line: 17, column: 38, scope: !30)
!35 = !DILocalVariable(name: "b", arg: 2, scope: !30, file: !1, line: 17, type: !10)
!36 = !DILocation(line: 17, column: 54, scope: !30)
!37 = !DILocation(line: 19, column: 5, scope: !30)
!38 = !DILocation(line: 19, column: 12, scope: !30)
!39 = !DILocation(line: 20, column: 25, scope: !40)
!40 = distinct !DILexicalBlock(scope: !30, file: !1, line: 19, column: 15)
!41 = !DILocation(line: 20, column: 9, scope: !40)
!42 = !DILocation(line: 20, column: 21, scope: !40)
!43 = !DILocation(line: 20, column: 23, scope: !40)
!44 = distinct !{!44, !37, !45}
!45 = !DILocation(line: 21, column: 5, scope: !30)
!46 = !DILocation(line: 22, column: 8, scope: !47)
!47 = distinct !DILexicalBlock(scope: !30, file: !1, line: 22, column: 8)
!48 = !DILocation(line: 22, column: 19, scope: !47)
!49 = !DILocation(line: 22, column: 50, scope: !47)
!50 = !DILocation(line: 22, column: 53, scope: !47)
!51 = !DILocation(line: 22, column: 64, scope: !47)
!52 = !DILocation(line: 22, column: 8, scope: !30)
!53 = !DILocation(line: 23, column: 12, scope: !54)
!54 = distinct !DILexicalBlock(scope: !55, file: !1, line: 23, column: 12)
!55 = distinct !DILexicalBlock(scope: !47, file: !1, line: 22, column: 97)
!56 = !DILocation(line: 23, column: 24, scope: !54)
!57 = !DILocation(line: 23, column: 26, scope: !54)
!58 = !DILocation(line: 23, column: 12, scope: !55)
!59 = !DILocation(line: 24, column: 28, scope: !60)
!60 = distinct !DILexicalBlock(scope: !54, file: !1, line: 23, column: 31)
!61 = !DILocation(line: 24, column: 12, scope: !60)
!62 = !DILocation(line: 24, column: 24, scope: !60)
!63 = !DILocation(line: 24, column: 26, scope: !60)
!64 = !DILocation(line: 25, column: 9, scope: !60)
!65 = !DILocation(line: 26, column: 5, scope: !55)
!66 = !DILocation(line: 27, column: 1, scope: !30)
