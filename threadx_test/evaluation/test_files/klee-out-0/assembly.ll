; ModuleID = '/home/klee/klee_test/threadx_test/evaluation/test_files/test_api_1.bc'
source_filename = "test_api_1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.test_structure_1 = type { i32, %struct.test_structure_1* }

@.str = private unnamed_addr constant [11 x i8] c"test_ptr_1\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !7 {
entry:
  %test_ptr_1 = alloca %struct.test_structure_1*, align 8
  call void @llvm.dbg.declare(metadata %struct.test_structure_1** %test_ptr_1, metadata !11, metadata !DIExpression()), !dbg !20
  %call = call i32 (%struct.test_structure_1**, i64, i8*, i32, ...) bitcast (i32 (...)* @klee_make_symbolic_controllable to i32 (%struct.test_structure_1**, i64, i8*, i32, ...)*)(%struct.test_structure_1** %test_ptr_1, i64 8, i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str, i64 0, i64 0), i32 1), !dbg !21
  %0 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1, align 8, !dbg !22
  call void @test_api_1(%struct.test_structure_1* %0), !dbg !23
  ret i32 0, !dbg !24
}

; Function Attrs: nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare dso_local i32 @klee_make_symbolic_controllable(...) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @test_api_1(%struct.test_structure_1* %test_ptr_1) #0 !dbg !25 {
entry:
  %test_ptr_1.addr = alloca %struct.test_structure_1*, align 8
  store %struct.test_structure_1* %test_ptr_1, %struct.test_structure_1** %test_ptr_1.addr, align 8
  call void @llvm.dbg.declare(metadata %struct.test_structure_1** %test_ptr_1.addr, metadata !28, metadata !DIExpression()), !dbg !29
  %0 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !30
  %cmp = icmp ugt %struct.test_structure_1* %0, inttoptr (i64 2415919103 to %struct.test_structure_1*), !dbg !32
  br i1 %cmp, label %if.then, label %lor.lhs.false, !dbg !33

lor.lhs.false:                                    ; preds = %entry
  %1 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !34
  %cmp1 = icmp ult %struct.test_structure_1* %1, inttoptr (i64 2147483648 to %struct.test_structure_1*), !dbg !35
  br i1 %cmp1, label %if.then, label %if.end6, !dbg !36

if.then:                                          ; preds = %lor.lhs.false, %entry
  %2 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !37
  %a = getelementptr inbounds %struct.test_structure_1, %struct.test_structure_1* %2, i32 0, i32 0, !dbg !40
  %3 = load i32, i32* %a, align 8, !dbg !40
  %cmp2 = icmp eq i32 %3, 0, !dbg !41
  br i1 %cmp2, label %if.then3, label %if.end, !dbg !42

if.then3:                                         ; preds = %if.then
  %4 = load %struct.test_structure_1*, %struct.test_structure_1** %test_ptr_1.addr, align 8, !dbg !43
  %p = getelementptr inbounds %struct.test_structure_1, %struct.test_structure_1* %4, i32 0, i32 1, !dbg !45
  %5 = load %struct.test_structure_1*, %struct.test_structure_1** %p, align 8, !dbg !45
  %p4 = getelementptr inbounds %struct.test_structure_1, %struct.test_structure_1* %5, i32 0, i32 1, !dbg !46
  %6 = load %struct.test_structure_1*, %struct.test_structure_1** %p4, align 8, !dbg !46
  %a5 = getelementptr inbounds %struct.test_structure_1, %struct.test_structure_1* %6, i32 0, i32 0, !dbg !47
  store i32 0, i32* %a5, align 8, !dbg !48
  br label %if.end, !dbg !49

if.end:                                           ; preds = %if.then3, %if.then
  br label %if.end6, !dbg !50

if.end6:                                          ; preds = %if.end, %lor.lhs.false
  ret void, !dbg !51
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone speculatable willreturn }
attributes #2 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5}
!llvm.ident = !{!6}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 11.0.0 (https://github.com/llvm/llvm-project.git 60a25202a7dd1e00067fcfce512086ebf3788537)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "test_api_1.c", directory: "/home/klee/klee_test/threadx_test/evaluation/test_files")
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
!13 = !DIDerivedType(tag: DW_TAG_typedef, name: "test_structure_1_t", file: !14, line: 9, baseType: !15)
!14 = !DIFile(filename: "./test_api.h", directory: "/home/klee/klee_test/threadx_test/evaluation/test_files")
!15 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "test_structure_1", file: !14, line: 6, size: 128, elements: !16)
!16 = !{!17, !18}
!17 = !DIDerivedType(tag: DW_TAG_member, name: "a", scope: !15, file: !14, line: 7, baseType: !10, size: 32)
!18 = !DIDerivedType(tag: DW_TAG_member, name: "p", scope: !15, file: !14, line: 8, baseType: !19, size: 64, offset: 64)
!19 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !15, size: 64)
!20 = !DILocation(line: 10, column: 27, scope: !7)
!21 = !DILocation(line: 11, column: 5, scope: !7)
!22 = !DILocation(line: 12, column: 16, scope: !7)
!23 = !DILocation(line: 12, column: 5, scope: !7)
!24 = !DILocation(line: 13, column: 1, scope: !7)
!25 = distinct !DISubprogram(name: "test_api_1", scope: !1, file: !1, line: 15, type: !26, scopeLine: 15, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!26 = !DISubroutineType(types: !27)
!27 = !{null, !12}
!28 = !DILocalVariable(name: "test_ptr_1", arg: 1, scope: !25, file: !1, line: 15, type: !12)
!29 = !DILocation(line: 15, column: 38, scope: !25)
!30 = !DILocation(line: 16, column: 8, scope: !31)
!31 = distinct !DILexicalBlock(scope: !25, file: !1, line: 16, column: 8)
!32 = !DILocation(line: 16, column: 19, scope: !31)
!33 = !DILocation(line: 16, column: 50, scope: !31)
!34 = !DILocation(line: 16, column: 53, scope: !31)
!35 = !DILocation(line: 16, column: 64, scope: !31)
!36 = !DILocation(line: 16, column: 8, scope: !25)
!37 = !DILocation(line: 17, column: 12, scope: !38)
!38 = distinct !DILexicalBlock(scope: !39, file: !1, line: 17, column: 12)
!39 = distinct !DILexicalBlock(scope: !31, file: !1, line: 16, column: 97)
!40 = !DILocation(line: 17, column: 24, scope: !38)
!41 = !DILocation(line: 17, column: 26, scope: !38)
!42 = !DILocation(line: 17, column: 12, scope: !39)
!43 = !DILocation(line: 18, column: 13, scope: !44)
!44 = distinct !DILexicalBlock(scope: !38, file: !1, line: 17, column: 31)
!45 = !DILocation(line: 18, column: 25, scope: !44)
!46 = !DILocation(line: 18, column: 28, scope: !44)
!47 = !DILocation(line: 18, column: 31, scope: !44)
!48 = !DILocation(line: 18, column: 32, scope: !44)
!49 = !DILocation(line: 19, column: 9, scope: !44)
!50 = !DILocation(line: 20, column: 5, scope: !39)
!51 = !DILocation(line: 21, column: 1, scope: !25)
