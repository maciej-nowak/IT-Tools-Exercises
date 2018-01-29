#include<iostream>
#include<fstream>
#include<string>

using namespace std;

ofstream rtfFile, psFile, htmlFile;
string name, surname, dateOfBirth, position, dateValid, company, part1, part2;

void cut(string company)
{
    if(company.size()>30)
    {
        int i=30;
        while(company[i]!=' ' && i<company.size()) i++;
        part1.assign(company,0,i+1);
        part2.assign(company,i+1,company.size()-i-1);
    }
    else
    {
        part1.assign(company,0,company.size()+1);
        part2="";
    }
}

void rtf(string name, string surname, string dateOfBirth, string position, string dateValid, string part1, string part2)
{
    rtfFile.open("file.rtf");
    rtfFile<<"{\\rtf1\\ansi\\deff0\n{\\colortbl;\\red0\\green0\blue0;\\red255\\green0\\blue0;\\red0\\green255\\blue0;\\red0\\green0\\blue255;}\n";
    rtfFile<<"\\trowd\\clbrdrt\\brdrs\\clbrdrl\\brdrs\\clbrdrb\\brdrs\\clbrdrr\\brdrs \n";
    rtfFile<<"\\cellx6000\\intbl \n";
    rtfFile<<"{\\cf4\\qc\\b "<<part1<<"\\line "<<part2<<" - przepustka\\b0\\line\\par} \n";
    rtfFile<<"\\b "<<name<<" "<<surname<<"\\b0\\par \n";
    rtfFile<<"\\b  Rok urodzenia: \\b0 "<<dateOfBirth<<" \\par \n";
    rtfFile<<"\\b  Stanowisko: \\b0 "<<position<<" \\par\\par \n";
    rtfFile<<"{\\qr\\cf2\\i\\b Wazna do: \\b0 "<<dateValid<<" \\i0\\line} \n";
    rtfFile<<"\\row \n}";
    rtfFile.close();
}

void ps(string name, string surname, string dateOfBirth, string position, string dateValid, string part1, string part2)
{
    psFile.open("file.ps");
    psFile<<"%!PS-Adobe-2.0\n\n";
    psFile<<"/Arial-Black findfont 10 scalefont setfont\n0 0 1 setrgbcolor\n70 800 moveto ("<<part1<<") show\n";
    psFile<<"70 785 moveto ("<<part2<<" - przepustka) show\n\n";
    psFile<<"0 0 0 setrgbcolor\n10 760 moveto ("<<name<<" "<<surname<<") show\n\n";
    psFile<<"10 740 moveto (Rok urodzenia: ) show\n/Arial findfont 10 scalefont setfont\n85 740 moveto ("<<dateOfBirth<<") show\n\n";
    psFile<<"/Arial-Black findfont 10 scalefont setfont\n10 720 moveto (Stanowisko: ) show\n/Arial findfont 10 scalefont setfont\n75 720 moveto ("<<position<<") show\n\n";
    psFile<<"/Arial-Black-Italic findfont 10 scalefont setfont\n1 0 0 setrgbcolor\n150 690 moveto (Wazna do: ) show\n/Arial-Italic findfont 10 scalefont setfont\n215 690 moveto ("<<dateValid<<") show\n\n";
    psFile<<"0 0 0 setrgbcolor\n8 810 moveto\n280 810 lineto\n280 680 lineto\n8 680 lineto\nclosepath\nstroke\n";
    psFile<<"/csquare {\nnewpath\n0 0 moveto\n0 1 lineto\n1 0 lineto\n0 -1 lineto\nclosepath\nsetrgbcolor\nfill\n} def\n";
    psFile<<"20 20 scale\n\n";
    psFile<<"9 37 translate\n1 0 0 csquare\n";
    psFile<<"1 0 translate\n0 1 0 csquare\n";
    psFile<<"1 0 translate\n0 0 1 csquare\n";
    psFile<<"1 0 translate\n1 1 0 csquare\n\n";
    psFile<<"showpage";
    psFile.close();
}

void html(string name, string surname, string dateOfBirth, string position, string dateValid, string part1, string part2)
{
    htmlFile.open("file.html");
    htmlFile<<"<html><head><title></title></head>\n";
    htmlFile<<"<body><table border=\"1\" cellpadding=\"1\" cellspacing=\"1\" style=\"width: 500px;\"><tbody><tr><td>\n";
    htmlFile<<"<p align=\"center\"><font color=\"blue\"><b>"<<part1<<"</b></font></p>\n";
    htmlFile<<"<p align=\"center\"><font color=\"blue\"><b>"<<part2<<" - przepustka"<<"</b></font></p><br />\n";
    htmlFile<<"<img src=\"image.jpg\" align=\"right\" />\n";
    htmlFile<<"<p><b>"<<name<<" "<<surname<<"</b></p>\n";
    htmlFile<<"<p><b>Rok urodzenia: </b>"<<dateOfBirth<<"</p>\n";
    htmlFile<<"<p><b>Stanowisko: </b>"<<position<<"</p><br />\n";
    htmlFile<<"<p align=\"right\"><font color=\"red\"><b>"<<"Wazna do: </b><i>"<<dateValid<<"</i></font></p>\n";
    htmlFile<<"</td></tr></tbody></table></body></html>";
    htmlFile.close();
}

int main()
{
    cout<<"Podaj imie"<<endl;
    getline(cin,name);
    cout<<"Podaj nazwisko"<<endl;
    getline(cin,surname);
    cout<<"Podaj rok urodzenia"<<endl;
    getline(cin,dateOfBirth);
    cout<<"Podaj stanowisko"<<endl;
    getline(cin,position);
    cout<<"Podaj date waznosci"<<endl;
    getline(cin,dateValid);
    cout<<"Podaj nazwe firmy"<<endl;
    getline(cin,company);

    cut(company);
    rtf(name,surname,dateOfBirth,position,dateValid,part1,part2);
    ps(name,surname,dateOfBirth,position,dateValid,part1,part2);
    html(name,surname,dateOfBirth,position,dateValid,part1,part2);
    cout<<part1<<endl<<part2<<endl;

    return 0;
}
