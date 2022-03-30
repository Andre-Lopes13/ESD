typedef struct pto
{
    float x;
    float y;
} tPonto;
void ptoCria(tPonto *p, float x, float y);
void ptoExibe(tPonto *pto);
int ptoGetX(tPonto pto);
int ptoGetY(tPonto pto);
void ptoSetX(tPonto *pto, float valor);
void ptoSetY(tPonto *pto, float valor);
void ptoAtribui(tPonto *pto, float x, float y);
int ptoDistancia(tPonto pt1, tPonto pt2);