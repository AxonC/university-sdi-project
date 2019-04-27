# Download the following

* https://github.com/jgm/pandoc/releases/tag/2.7.2
* https://github.com/Wandmalfarbe/pandoc-latex-template/releases/tag/v1.2.2
* LaTeX

# Setup

From the Pandoc Latex Template download, copy `eisvogel.tex` to

~/.pandoc/templates/ (if this doesn't exist create it)

Rename `eisvogel.tex` to `eisvogel.latex`

# Editing the Document

Markdown is easiest to use (you can use Sublime, VS Code etc) but you can use LaTex editor with the .tex file.

Once you have finished editing the .md file or the .tex file, run the respective command to compile everything (run them from the documentation folder from git):

## Create .tex & .pdf from the edited the .md file

`pandoc --filter pandoc-citeproc -s trekstar-documentation.md -o trekstar-documentation.tex --template eisvogel`\
`pandoc --filter pandoc-citeproc trekstar-documentation.md -o trekstar-documentation.pdf --template eisvogel`

## Create .md & .pdf from the edited the .tex file

`pandoc --filter pandoc-citeproc trekstar-documentation.tex -o trekstar-documentation.md --template eisvogel`\
`pandoc --filter pandoc-citeproc trekstar-documentation.tex -o trekstar-documentation.pdf --template eisvogel`