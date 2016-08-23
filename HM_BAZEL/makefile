all: build

BAZEL=$(shell which bazel)

.PHONY: build
build : 
    $(BAZEL) build //NEURAL_CUP:NEURAL_CUP
    $(BAZEL) build //TLibVideoIO:TLibVideoIO
    $(BAZEL) build //libmd5:libmd5
    $(BAZEL) build //TLibCommon:TLibCommon
    $(BAZEL) build //TLibDecoder:TLibDecoder
    $(BAZEL) build //TLibEncoder:TLibEncoder
    $(BAZEL) build //TAppCommon:TAppCommon
    $(BAZEL) build //TAppDecoder:TAppDecoder
    $(BAZEL) build //TAppEncoder:TAppEncoder

.PHONY: clean
clean :
    $(BAZEL) clean

