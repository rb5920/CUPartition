# Description:
#   Tensorflow C++ inference example for labeling images.

visibility = ["//visibility:public"],

#licenses(["notice"])  # Apache 2.0

#exports_files(["LICENSE"])


cc_binary(
    name = "testneural",
    srcs = ["neuraltest.cc"],
	copts = ["-Itensorflow/HM_BAZEL/NEURAL_CUP"],
    deps = [
        "//tensorflow/HM_BAZEL/NEURAL_CUP:NEURAL_CUP",
    ],
	visibility = ["//visibility:public"],
)


