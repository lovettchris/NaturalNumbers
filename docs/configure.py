import os
import glob
import sys

script_path = os.path.dirname(__file__)
sys.path += [os.path.join(script_path, "book")]
import ninja_syntax


def ignore(d):
    return d.startswith("build") or d.startswith("lean_packages") or \
        d.startswith("log") or d.startswith("__pycache__") or d.startswith("docs")


def createNinja(f):
    ninja = ninja_syntax.Writer(f)
    ninja.rule(name="alectryon", command="alectryon --frontend lean4+markup $in" +
        " --lake lakefile.lean --backend webpage -o $out")
    ninja.rule(name="book", command="mdbook build")
    ninja.rule(name="lake", command="lake build $in")

    os.chdir(os.path.join(script_path))
    print("collecting .lean source files in Examples and Monads folders...")
    all_files = []
    for d in ["."] + os.listdir():
        if os.path.isdir(d) and not ignore(d):
            print(f"collecting lean files in {d}")
            all_ileans = []
            for path in glob.glob(f"{d}/*.lean"):
                n = path.replace('\\', '/')
                if "lakefile.lean" not in n:
                    ninja.build(outputs=f"{n}.md", rule="alectryon", inputs=n)
                    fn = os.path.splitext(n)[0]
                    all_ileans += [f"build/lib/{fn}.olean", f"build/lib/{fn}.ilean"]
                    all_files += [f"{n}.md"]
            if d != "." and len(all_ileans) > 0:
                ninja.build(outputs=all_ileans, rule="lake", inputs=d)

    print("collecting all other md files...")
    for path in glob.glob("**/*.md", recursive=True):
        if not ignore(path) and not path.endswith(".lean.md"):
            n = path.replace('\\', '/')
            if n not in all_files:
                all_files += [n]

    all_files += ["book.toml"]
    ninja.build(outputs="docs/index.html", rule="book", inputs=all_files)


if __name__ == '__main__':
    with open("build.ninja", 'w') as f:
        createNinja(f)
    print("Now you can run 'ninja' to build the docs then you can open ./docs/index.html in your browser.")
