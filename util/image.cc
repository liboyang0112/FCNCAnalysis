#include "TCanvas.h"
#include "TBox.h"
#include "TLatex.h"
int main(int argc, char const *argv[])
{
	
   TCanvas *canv = new TCanvas("image","image",4*141/0.9,400/0.9);
   canv->Divide(2,2);
   TPad *p[4];
   p[0] = (TPad*)(canv->cd(1));
   p[0]->SetFillColor(5);
   p[0]-> SetPad(0.1,0.55,0.56,1);
   TLatex *t = new TLatex();
   t->SetNDC();
   t->SetTextAlign(22);
   t->SetTextFont(64);
   t->SetTextSizePixels(50);
   t->DrawLatex(0.5,0.5,"SR");
   t->Draw();

   p[1] = (TPad*)(canv->cd(2));
   p[1]->SetFillColor(8);
   p[1]->SetPad(0.1,0.1,0.56,0.55);

   p[2] = (TPad*)(canv->cd(3));
   p[2]->SetFillColor(8);
   p[2]->SetPad(0.55,0.1,1,0.55);

   t->DrawLatex(0.5,0.5,"nOS CR");
   t->Draw();

   p[3] = (TPad*)(canv->cd(4));
   p[3]->SetFillColor(8);
   p[3]->SetPad(0.55,0.55,1,1);

   canv->cd(0);
   t->SetTextSizePixels(30);
   t->DrawLatex(0.325,0.05,"OS");
   t->DrawLatex(0.775,0.05,"SS");
   t->SetTextAngle(90);
   t->DrawLatex(0.05,0.325,"Loose");
   t->DrawLatex(0.05,0.775,"Medium");

   canv->SaveAs("test.pdf");
	return 0;
}