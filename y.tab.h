typedef union {
	int ival;
	float fval;
	char *sval;
	bool bval;
	struct exptype *eval;
	struct num *nval;
} YYSTYPE;
#define	ENDL	258
#define	END	259
#define	PROGRAM	260
#define	CONST	261
#define	S	262
#define	INC	263
#define	DEC	264
#define	INT	265
#define	FLOAT	266
#define	BOOL	267
#define	AND	268
#define	OR	269
#define	NOT	270
#define	WHILE	271
#define	IF	272
#define	THEN	273
#define	ELSE	274
#define	ENDIF	275
#define	SWITCH	276
#define	CASE	277
#define	DEFAULT	278
#define	BREAK	279
#define	CONTINUE	280
#define	ASSIGN	281
#define	PLUS	282
#define	MINUS	283
#define	MUL	284
#define	DIV	285
#define	LB	286
#define	RB	287
#define	GTE	288
#define	LTE	289
#define	GT	290
#define	LT	291
#define	EQ	292
#define	NE	293
#define	LC	294
#define	COLON	295
#define	RC	296
#define	DO	297
#define	FOR	298
#define	FNUM	299
#define	INUM	300
#define	TRUE	301
#define	FALSE	302
#define	IDENTIFIER	303


extern YYSTYPE yylval;
