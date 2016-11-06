/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20160324

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser/attack_parser.y"

/*
 * Copyright (c) 2007,2008,2009,2010 Mij <mij@sshguard.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * SSHGuard. See http://www.sshguard.net
 */

#include <assert.h>
#include <string.h>

#include "parser/parser.h"
#include "sshguard.h"
#include "sshguard_logsuck.h"

 /* stuff exported by the scanner */
extern void scanner_init();
extern void scanner_fin();
extern int yylex();

static void yyerror(attack_t *, const char *);

 /* Metadata used by the parser */
 /* per-source metadata */
typedef struct {
    sourceid_t id;
    int last_was_recognized;
    attack_t last_attack;
    unsigned int last_multiplicity;
} source_metadata_t;

 /* parser metadata */
static struct {
    unsigned int num_sources;
    int current_source_index;
    source_metadata_t sources[MAX_FILES_POLLED];
} parser_metadata = { 0, -1 };

#line 60 "parser/attack_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    char *str;
    int num;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 85 "parser/attack_parser.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(attack_t *attack)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(attack_t *attack, const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(attack, msg)
#endif

extern int YYPARSE_DECL();

#define IPv4 257
#define IPv6 258
#define HOSTADDR 259
#define WORD 260
#define INTEGER 261
#define SYSLOG_BANNER_PID 262
#define SOCKLOG_BANNER_PID 263
#define LAST_LINE_REPEATED_N_TIMES 264
#define SYSLOG_BANNER 265
#define TIMESTAMP_SYSLOG 266
#define TIMESTAMP_ISO8601 267
#define TIMESTAMP_TAI64 268
#define AT_TIMESTAMP_TAI64 269
#define METALOG_BANNER 270
#define SOCKLOG_BANNER 271
#define SSH_INVALUSERPREF 272
#define SSH_NOTALLOWEDPREF 273
#define SSH_NOTALLOWEDSUFF 274
#define SSH_LOGINERR_PREF 275
#define SSH_LOGINERR_SUFF 276
#define SSH_LOGINERR_PAM 277
#define SSH_VIA 278
#define SSH_NOIDENTIFSTR 279
#define SSH_BADPROTOCOLIDENTIF 280
#define SSH_BADPROTOCOLIDENTIF_SUFF 281
#define SSH_BADKEX_PREF 282
#define SSH_BADKEX_SUFF 283
#define SSH_DISCONNECT_PREF 284
#define SSH_PREAUTH_SUFF 285
#define DOVECOT_IMAP_LOGINERR_PREF 286
#define DOVECOT_IMAP_LOGINERR_SUFF 287
#define UWIMAP_LOGINERR 288
#define CYRUSIMAP_SASL_LOGINERR_PREF 289
#define CYRUSIMAP_SASL_LOGINERR_SUFF 290
#define CUCIPOP_AUTHFAIL 291
#define EXIM_ESMTP_AUTHFAIL_PREF 292
#define EXIM_ESMTP_AUTHFAIL_SUFF 293
#define SENDMAIL_RELAYDENIED_PREF 294
#define SENDMAIL_RELAYDENIED_SUFF 295
#define SENDMAIL_AUTHFAILURE_PREF 296
#define SENDMAIL_AUTHFAILURE_SUFF 297
#define POSTFIX_NO_AUTH_PREF 298
#define POSTFIX_SASL_LOGINERR_PREF 299
#define POSTFIX_SASL_LOGINERR_SUFF 300
#define FREEBSDFTPD_LOGINERR_PREF 301
#define FREEBSDFTPD_LOGINERR_SUFF 302
#define PROFTPD_LOGINERR_PREF 303
#define PROFTPD_LOGINERR_SUFF 304
#define PUREFTPD_LOGINERR_PREF 305
#define PUREFTPD_LOGINERR_SUFF 306
#define VSFTPD_LOGINERR_PREF 307
#define VSFTPD_LOGINERR_SUFF 308
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    2,    2,    3,    4,    5,
    5,    6,    6,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    1,   20,   20,   20,    8,
    8,    8,    8,    8,   21,   21,   22,   22,   22,   23,
   23,   24,   25,    9,   10,   11,   12,   13,   14,   14,
   15,   15,   16,   17,   18,   19,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    2,    2,    2,    2,    2,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    3,    3,    2,    3,    2,
    3,    3,    3,    3,    4,    3,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,   26,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   13,
    1,    2,    3,    4,    5,   12,   14,   15,   16,   17,
   18,   19,   20,   21,   22,   23,   24,   25,   30,   31,
   32,   33,   34,    6,   10,    7,    8,    9,   11,   27,
   28,   29,   35,    0,    0,    0,   40,    0,    0,    0,
    0,    0,    0,   47,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   36,   37,   39,   42,   43,   41,   44,
    0,   46,   48,   49,   50,   52,   51,   53,   54,   55,
   56,   45,
};
static const YYINT yydgoto[] = {                         29,
   30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   46,   47,   48,   63,
   49,   50,   51,   52,   53,
};
static const YYINT yysindex[] = {                      -241,
 -205, -205,    0, -205, -205, -205, -205, -232, -232, -232,
 -232, -232, -232, -232, -232, -232,  -83, -232, -232, -232,
 -232, -232, -232, -232, -232, -232, -232, -232,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -254, -243, -238,    0, -246, -239, -248,
 -245, -232, -244,    0, -237, -234, -228,  -44, -235, -250,
 -233, -252, -230,    0,    0,    0,    0,    0,    0,    0,
  -20,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   76,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,  102,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   -9,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 109
static const YYINT yytable[] = {                         64,
   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
    1,    2,    3,    4,   60,   61,   62,    5,    6,    7,
    8,    9,   85,   10,   87,   11,   89,   12,   13,   86,
   14,   90,   15,   88,   16,   92,   17,   18,   96,   19,
   20,   98,   21,  100,   22,   93,   23,   24,    3,   25,
   94,   26,   91,   27,   97,   28,    8,    9,   95,   10,
   99,   11,  102,   12,   13,   38,   14,  101,   15,    0,
   16,    0,   17,   18,    0,   19,   20,    0,   21,    0,
   22,    0,   23,   24,    0,   25,    0,   26,    0,   27,
    0,   28,   54,   55,    0,   56,   57,   58,   59,
};
static const YYINT yycheck[] = {                          9,
   10,   11,   12,   13,   14,   15,   16,   91,   18,   19,
   20,   21,   22,   23,   24,   25,   26,   27,   28,  274,
  262,  263,  264,  265,  257,  258,  259,  269,  270,  271,
  272,  273,  276,  275,  281,  277,  285,  279,  280,  278,
  282,  287,  284,  283,  286,  290,  288,  289,   93,  291,
  292,  302,  294,  306,  296,  293,  298,  299,  264,  301,
  295,  303,   72,  305,  300,  307,  272,  273,  297,  275,
  304,  277,   93,  279,  280,    0,  282,  308,  284,   -1,
  286,   -1,  288,  289,   -1,  291,  292,   -1,  294,   -1,
  296,   -1,  298,  299,   -1,  301,   -1,  303,   -1,  305,
   -1,  307,    1,    2,   -1,    4,    5,    6,    7,
};
#define YYFINAL 29
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#define YYUNDFTOKEN 336
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IPv4","IPv6","HOSTADDR",
"WORD","INTEGER","SYSLOG_BANNER_PID","SOCKLOG_BANNER_PID",
"LAST_LINE_REPEATED_N_TIMES","SYSLOG_BANNER","TIMESTAMP_SYSLOG",
"TIMESTAMP_ISO8601","TIMESTAMP_TAI64","AT_TIMESTAMP_TAI64","METALOG_BANNER",
"SOCKLOG_BANNER","SSH_INVALUSERPREF","SSH_NOTALLOWEDPREF","SSH_NOTALLOWEDSUFF",
"SSH_LOGINERR_PREF","SSH_LOGINERR_SUFF","SSH_LOGINERR_PAM","SSH_VIA",
"SSH_NOIDENTIFSTR","SSH_BADPROTOCOLIDENTIF","SSH_BADPROTOCOLIDENTIF_SUFF",
"SSH_BADKEX_PREF","SSH_BADKEX_SUFF","SSH_DISCONNECT_PREF","SSH_PREAUTH_SUFF",
"DOVECOT_IMAP_LOGINERR_PREF","DOVECOT_IMAP_LOGINERR_SUFF","UWIMAP_LOGINERR",
"CYRUSIMAP_SASL_LOGINERR_PREF","CYRUSIMAP_SASL_LOGINERR_SUFF",
"CUCIPOP_AUTHFAIL","EXIM_ESMTP_AUTHFAIL_PREF","EXIM_ESMTP_AUTHFAIL_SUFF",
"SENDMAIL_RELAYDENIED_PREF","SENDMAIL_RELAYDENIED_SUFF",
"SENDMAIL_AUTHFAILURE_PREF","SENDMAIL_AUTHFAILURE_SUFF","POSTFIX_NO_AUTH_PREF",
"POSTFIX_SASL_LOGINERR_PREF","POSTFIX_SASL_LOGINERR_SUFF",
"FREEBSDFTPD_LOGINERR_PREF","FREEBSDFTPD_LOGINERR_SUFF","PROFTPD_LOGINERR_PREF",
"PROFTPD_LOGINERR_SUFF","PUREFTPD_LOGINERR_PREF","PUREFTPD_LOGINERR_SUFF",
"VSFTPD_LOGINERR_PREF","VSFTPD_LOGINERR_SUFF",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : text",
"text : syslogent",
"text : multilogent",
"text : metalogent",
"text : socklogent",
"text : logmsg",
"syslogent : SYSLOG_BANNER_PID logmsg",
"syslogent : SYSLOG_BANNER logmsg",
"multilogent : AT_TIMESTAMP_TAI64 logmsg",
"metalogent : METALOG_BANNER logmsg",
"socklogent : SOCKLOG_BANNER_PID logmsg",
"socklogent : SOCKLOG_BANNER logmsg",
"logmsg : msg_single",
"logmsg : msg_multiple",
"msg_single : sshmsg",
"msg_single : dovecotmsg",
"msg_single : uwimapmsg",
"msg_single : cyrusimapmsg",
"msg_single : cucipopmsg",
"msg_single : eximmsg",
"msg_single : sendmailmsg",
"msg_single : postfixmsg",
"msg_single : freebsdftpdmsg",
"msg_single : proftpdmsg",
"msg_single : pureftpdmsg",
"msg_single : vsftpdmsg",
"msg_multiple : LAST_LINE_REPEATED_N_TIMES",
"addr : IPv4",
"addr : IPv6",
"addr : HOSTADDR",
"sshmsg : ssh_illegaluser",
"sshmsg : ssh_authfail",
"sshmsg : ssh_noidentifstring",
"sshmsg : ssh_badprotocol",
"sshmsg : ssh_badkex",
"ssh_illegaluser : SSH_INVALUSERPREF addr",
"ssh_illegaluser : SSH_NOTALLOWEDPREF addr SSH_NOTALLOWEDSUFF",
"ssh_authfail : SSH_LOGINERR_PREF addr SSH_LOGINERR_SUFF",
"ssh_authfail : SSH_LOGINERR_PAM addr",
"ssh_authfail : SSH_LOGINERR_PAM addr SSH_VIA",
"ssh_noidentifstring : SSH_NOIDENTIFSTR addr",
"ssh_noidentifstring : SSH_DISCONNECT_PREF addr SSH_PREAUTH_SUFF",
"ssh_badprotocol : SSH_BADPROTOCOLIDENTIF addr SSH_BADPROTOCOLIDENTIF_SUFF",
"ssh_badkex : SSH_BADKEX_PREF addr SSH_BADKEX_SUFF",
"dovecotmsg : DOVECOT_IMAP_LOGINERR_PREF addr DOVECOT_IMAP_LOGINERR_SUFF",
"uwimapmsg : UWIMAP_LOGINERR '[' addr ']'",
"cyrusimapmsg : CYRUSIMAP_SASL_LOGINERR_PREF addr CYRUSIMAP_SASL_LOGINERR_SUFF",
"cucipopmsg : CUCIPOP_AUTHFAIL addr",
"eximmsg : EXIM_ESMTP_AUTHFAIL_PREF addr EXIM_ESMTP_AUTHFAIL_SUFF",
"sendmailmsg : SENDMAIL_RELAYDENIED_PREF addr SENDMAIL_RELAYDENIED_SUFF",
"sendmailmsg : SENDMAIL_AUTHFAILURE_PREF addr SENDMAIL_AUTHFAILURE_SUFF",
"postfixmsg : POSTFIX_SASL_LOGINERR_PREF addr POSTFIX_SASL_LOGINERR_SUFF",
"postfixmsg : POSTFIX_NO_AUTH_PREF addr ']'",
"freebsdftpdmsg : FREEBSDFTPD_LOGINERR_PREF addr FREEBSDFTPD_LOGINERR_SUFF",
"proftpdmsg : PROFTPD_LOGINERR_PREF addr PROFTPD_LOGINERR_SUFF",
"pureftpdmsg : PUREFTPD_LOGINERR_PREF addr PUREFTPD_LOGINERR_SUFF",
"vsftpdmsg : VSFTPD_LOGINERR_PREF addr VSFTPD_LOGINERR_SUFF",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 299 "parser/attack_parser.y"

static void yyerror(__attribute__((unused)) attack_t *a,
    __attribute__((unused)) const char *s) { /* do nothing */ }

static void init_structures(unsigned int source_id, attack_t *attack) {
    unsigned int cnt;

    /* add metadata for this source, if new */
    for (cnt = 0; cnt < parser_metadata.num_sources; ++cnt) {
        if (parser_metadata.sources[cnt].id == source_id) break;
    }
    if (cnt == parser_metadata.num_sources) {
        /* new source! */
        assert(cnt < MAX_FILES_POLLED);
        parser_metadata.sources[cnt].id = source_id;
        parser_metadata.sources[cnt].last_was_recognized = 0;
        parser_metadata.sources[cnt].last_multiplicity = 1;

        parser_metadata.num_sources++;
    }
    
    /* initialize the attack structure */
    attack->dangerousness = DEFAULT_ATTACKS_DANGEROUSNESS;
    attack->source = 0;

    /* set current source index */
    parser_metadata.current_source_index = cnt;
}

int parse_line(int source_id, char *str, attack_t *attack) {
    int ret;

    /* initialize parser structures */
    init_structures(source_id, attack);

    /* initialize scanner, do parse, finalize scanner */
    scanner_init(str);
    ret = yyparse(attack);
    scanner_fin();

    /* do post-parsing oeprations */
    if (ret == 0) {
        /* message recognized */
        /* update metadata on this source */
        parser_metadata.sources[parser_metadata.current_source_index].last_was_recognized = 1;
        parser_metadata.sources[parser_metadata.current_source_index].last_attack = *attack;
    } else {
        /* message not recognized */
        parser_metadata.sources[parser_metadata.current_source_index].last_was_recognized = 0;
    }

    return ret;
}
#line 448 "parser/attack_parser.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 6:
#line 126 "parser/attack_parser.y"
	{ attack->source = yystack.l_mark[-1].num; }
break;
case 10:
#line 143 "parser/attack_parser.y"
	{ attack->source = yystack.l_mark[-1].num; }
break;
case 12:
#line 150 "parser/attack_parser.y"
	{   parser_metadata.sources[parser_metadata.current_source_index].last_multiplicity = 1;    }
break;
case 13:
#line 152 "parser/attack_parser.y"
	{   parser_metadata.sources[parser_metadata.current_source_index].last_multiplicity = yystack.l_mark[0].num; }
break;
case 14:
#line 156 "parser/attack_parser.y"
	{   attack->service = SERVICES_SSH; }
break;
case 15:
#line 157 "parser/attack_parser.y"
	{   attack->service = SERVICES_DOVECOT; }
break;
case 16:
#line 158 "parser/attack_parser.y"
	{   attack->service = SERVICES_UWIMAP; }
break;
case 17:
#line 159 "parser/attack_parser.y"
	{   attack->service = SERVICES_CYRUSIMAP; }
break;
case 18:
#line 160 "parser/attack_parser.y"
	{   attack->service = SERVICES_CUCIPOP; }
break;
case 19:
#line 161 "parser/attack_parser.y"
	{   attack->service = SERVICES_EXIM; }
break;
case 20:
#line 162 "parser/attack_parser.y"
	{   attack->service = SERVICES_SENDMAIL; }
break;
case 21:
#line 163 "parser/attack_parser.y"
	{   attack->service = SERVICES_POSTFIX; }
break;
case 22:
#line 164 "parser/attack_parser.y"
	{   attack->service = SERVICES_FREEBSDFTPD; }
break;
case 23:
#line 165 "parser/attack_parser.y"
	{   attack->service = SERVICES_PROFTPD; }
break;
case 24:
#line 166 "parser/attack_parser.y"
	{   attack->service = SERVICES_PUREFTPD; }
break;
case 25:
#line 167 "parser/attack_parser.y"
	{   attack->service = SERVICES_VSFTPD; }
break;
case 26:
#line 172 "parser/attack_parser.y"
	{
                        /* the message repeated, was it an attack? */
                        if (! parser_metadata.sources[parser_metadata.current_source_index].last_was_recognized) {
                            /* make sure this doesn't get recognized as an attack */
                            YYABORT;
                        }
                        
                        /* got a repeated attack */
                        *attack = parser_metadata.sources[parser_metadata.current_source_index].last_attack;
                        /* restore previous "genuine" dangerousness, and build new one */
                        attack->dangerousness = yystack.l_mark[0].num * (attack->dangerousness / parser_metadata.sources[parser_metadata.current_source_index].last_multiplicity);

                        /* pass up the multiplicity of this attack */
                        yyval.num = yystack.l_mark[0].num;
                    }
break;
case 27:
#line 191 "parser/attack_parser.y"
	{
                        attack->address.kind = ADDRKIND_IPv4;
                        strcpy(attack->address.value, yystack.l_mark[0].str);
                    }
break;
case 28:
#line 195 "parser/attack_parser.y"
	{
                        attack->address.kind = ADDRKIND_IPv6;
                        strcpy(attack->address.value, yystack.l_mark[0].str);
                    }
break;
case 29:
#line 199 "parser/attack_parser.y"
	{
                        if (!attack_from_hostname(attack, yystack.l_mark[0].str)) {
                            YYABORT;
                        }
                    }
break;
case 50:
#line 271 "parser/attack_parser.y"
	{ attack->dangerousness *= 2; }
break;
#line 758 "parser/attack_parser.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
