#!/bin/bash
rename "s/.cpp/.cc/" code/*.cpp;
rename "s/.cp/.cc/" code/*.cp;
read p
echo "\\author{$p}" > olol
read p
echo "\\newcommand{\\myschool}{$p}" >> olol
while read p; do
    echo $p
done < skeleton >> olol
while read p; do
    if [ -z $p ]
    then continue
    fi
    if [[ $p == *":" ]];
    then
        echo "\\section{"${p%:}"}"
    else
	if [[ $p == *"#" ]];
	then
	    echo "\\includegraphics[scale=0.9]{math/"${p%#}".png}\\newpage"
	else
	    echo "\\subsection{"$p"}{\\scriptsize\\lstinputlisting{code/"$p".cc}}"
	fi
    fi
done >> olol
echo "\\end{multicols}
\\end{document}" >> olol
xelatex olol
xelatex olol
mv "olol.pdf" "notebook.pdf"
rm olol*
