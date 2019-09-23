CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = 6;
	rq = 0;
	tid = 1698;
	title = 169802;

	CNtlTSGroup
	{
		gid = 0;

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
		CDboTSContGAct
		{
			cid = 2;
			elnk = 252;
			nextlnk = 3;
			prelnk = "1;";

			CDboTSActNPCConv
			{
				conv = 169809;
				ctype = 1;
				idx = 5311101;
				taid = 2;
			}
			CDboTSActSToCEvt
			{
				apptype = 0;
				cnt1 = 1;
				eitype = 0;
				idx0 = 4654100;
				cnt0 = 1;
				cnt2 = 1;
				ectype = -1;
				etype = 0;
				idx1 = 3504100;
				taid = 3;
				esctype = 0;
				idx2 = 4264100;
			}
			CDboTSActRegQInfo
			{
				cont = 169808;
				m1fx = "-125.449997";
				m2fz = "-34.070000";
				m1fy = "0.000000";
				sort = 169805;
				m2widx = 9;
				grade = 132203;
				m1pat = 1;
				m1widx = 9;
				rwd = 100;
				taid = 1;
				gtype = 3;
				area = 169801;
				goal = 169804;
				m0fz = "-9.450000";
				m0widx = 9;
				m1ttip = 169816;
				m2fy = "0.000000";
				m2pat = 1;
				scitem = -1;
				stype = 2;
				m0fy = "0.000000";
				m0pat = 1;
				m1fz = "27.090000";
				m2fx = "-134.550003";
				m2ttip = 169817;
				m0fx = "-166.690002";
				m0ttip = 169815;
				title = 169802;
			}
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 169808;
			gtype = 3;
			oklnk = 2;
			area = 169801;
			goal = 169804;
			sort = 169805;
			prelnk = "0;";
			ds = 1;
			grade = 132203;
			rwd = 100;
			title = 169802;
		}
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 169814;
			nextlnk = 101;
			rwdexp = 0;
			rwdtbl = 169801;
			rwdtype = 0;
			ltime = -1;
			prelnk = "3;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "5311101;";
			}
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
			stdiag = 169807;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 49;
			}
			CDboTSCheckClrQst
			{
				and = "1696;";
				flink = 1;
				flinknextqid = "1699;";
				not = 0;
			}
			CDboTSClickNPC
			{
				npcidx = "5311101;";
			}
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

