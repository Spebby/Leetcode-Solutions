{
  description = "LeetCode dev environment using leetgo with C and Python support";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            leetgo

            # CXX
            clang
            gcc
            gdb
            gnumake

            # Python
            python3
            python3Packages.pip
          ];

          shellHook = ''
            echo "LeetCode development environment loaded."
            echo "- Run 'leetgo new <slug>' to fetch a new problem."
            echo "- Write solutions in C or Python."
          '';
        };
      }
    );
}
