/* -*- C++ -*- */
#ifndef RSITE_ARDUINO_MENU_HTMLFMT
  #define RSITE_ARDUINO_MENU_HTMLFMT
  #include "../menu.h"

  namespace Menu {

    template<class T>
    class htmlFmt:public T {
      public:
        using T::T;
        result fmtStart(menuOut::fmtParts part,navNode &nav,idx_t panelNr,idx_t idx=-1) override {
          switch(part) {
            case menuOut::fmtPanel:
              T::operator<<("<div id=\"panel\" class=\"panel\">");
              break;
            case menuOut::fmtTitle:
              T::operator<<("<h2 class=\"title\">");
              break;
            case menuOut::fmtBody:
              T::operator<<("<ul class=\"ops\">");
              break;
            case menuOut::fmtOp:
              T::operator<<("<li class=\"op\"><a href=\"/")<<(idx+1)<<"\">";
              break;
            case menuOut::fmtIdx:break;
            case menuOut::fmtCursor:break;
            case menuOut::fmtOpBody:break;
            case menuOut::fmtPreview:break;
            default:break;
          }
          return proceed;
        }
        result fmtEnd(menuOut::fmtParts part,navNode &nav,idx_t panelNr,idx_t idx=-1) override {
          switch(part) {
            case menuOut::fmtPanel:
              T::operator<<("</div>");
              break;
            case menuOut::fmtTitle:
              T::operator<<("</h2>");
              break;
            case menuOut::fmtBody:
              T::operator<<("</ul>");
              break;
            case menuOut::fmtOp:
              T::operator<<("</a></li>");
              break;
            case menuOut::fmtIdx:break;
            case menuOut::fmtCursor:break;
            case menuOut::fmtOpBody:break;
            case menuOut::fmtPreview:break;
            default:break;
          }
          return proceed;
        }
    };
  }//namespace
#endif