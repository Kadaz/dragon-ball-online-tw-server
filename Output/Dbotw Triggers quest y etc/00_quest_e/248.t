CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = 1;
	rq = 0;
	tid = 248;
	title = 24802;

	CNtlTSGroup
	{
		gid = 0;

		CDboTSContGAct
		{
			cid = 252;
			elnk = 255;
			nextlnk = 253;
			prelnk = "2;";
		}
		CDboTSContEnd
		{
			cid = 254;
			prelnk = "101;";
			type = 1;
		}
		CDboTSContEnd
		{
			cid = 253;
			prelnk = "0;252;1;";
			type = 0;
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 24807;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckPCRace
			{
				raceflg = 2;
			}
			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 9;
			}
			CDboTSClickNPC
			{
				npcidx = "4511403;";
			}
			CDboTSCheckClrQst
			{
				and = "247;";
				flink = 1;
				flinknextqid = "2015;";
				not = 0;
			}
		}
		CDboTSContGAct
		{
			cid = 2;
			elnk = 252;
			nextlnk = 3;
			prelnk = "1;";

			CDboTSActNPCConv
			{
				conv = 24809;
				ctype = 1;
				idx = 4511403;
				taid = 2;
			}
			CDboTSActSToCEvt
			{
				apptype = 0;
				cnt1 = 1;
				eitype = 0;
				idx0 = 5612108;
				cnt0 = 7;
				cnt2 = 0;
				ectype = -1;
				etype = 0;
				idx1 = 5611104;
				taid = 3;
				esctype = 0;
				idx2 = -1;
			}
			CDboTSActRegQInfo
			{
				cont = 24808;
				m3widx = 1;
				m1fy = "0.000000";
				sort = 24805;
				m2widx = 1;
				grade = 132203;
				m1pat = 1;
				m1widx = 1;
				m3fx = "4276.689941";
				rwd = 100;
				taid = 1;
				gtype = 3;
				m3fy = "0.000000";
				area = 24801;
				goal = 24804;
				m0fz = "-3089.419922";
				m0widx = 1;
				m1ttip = 24816;
				m2fy = "0.000000";
				m2pat = 2;
				m3fz = "-2818.330078";
				m3ttip = 24815;
				scitem = -1;
				stype = 16;
				m0fy = "0.000000";
				m0pat = 2;
				m1fz = "-3235.590088";
				m2fx = "4423.370117";
				m2ttip = 24815;
				m0fx = "4296.399902";
				m0ttip = 24815;
				m3pat = 2;
				title = 24802;
				m1fx = "4401.819824";
				m2fz = "-3230.810059";
			}
		}
		CDboTSContGAct
		{
			cid = 101;
			elnk = 255;
			nextlnk = 254;
			prelnk = "100;";

			CDboTSActSToCEvt
			{
				apptype = 0;
				cnt1 = 0;
				eitype = 0;
				idx0 = -1;
				cnt0 = 0;
				cnt2 = 0;
				ectype = -1;
				etype = 1;
				idx1 = -1;
				taid = 1;
				esctype = 0;
				idx2 = -1;
			}
		}
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 24814;
			nextlnk = 101;
			rwdexp = 0;
			rwdtbl = 24801;
			rwdtype = 0;
			ltime = -1;
			prelnk = "3;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "4751202;";
			}
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 24808;
			gtype = 3;
			oklnk = 2;
			area = 24801;
			goal = 24804;
			sort = 24805;
			prelnk = "0;";
			ds = 1;
			grade = 132203;
			rwd = 100;
			title = 24802;
		}
		CDboTSContGCond
		{
			cid = 3;
			prelnk = "2;";
			nolnk = 255;
			rm = 0;
			yeslnk = 100;

			CDboTSCheckSToCEvt
			{
				itype = 0;
			}
		}
	}
}

