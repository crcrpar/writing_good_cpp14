load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
  name = "hello-world",
  deps = [
    "@com_google_absl//absl/strings",
    "@com_google_absl//absl/types:span",
  ],
  srcs = ["hello_world.cpp"],
)

cc_binary(
  name = "pfo",
  srcs = ["pointer_from_owner.cpp"],
)

cc_binary(
  name = "shared_ptr",
  srcs = ["shared_ptr_vec_int.cpp"],
)
