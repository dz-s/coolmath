{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "calc.cc" ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")",
        "/usr/local/boost_1_62_0"
      ]
    }
  ]
}

