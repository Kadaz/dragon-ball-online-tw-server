CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = 5;
	rq = 0;
	tid = 1321;
	title = 132102;

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
		CDboTSContEnd
		{
			cid = 253;
			prelnk = "0;252;1;";
			type = 0;
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 132107;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 43;
			}
			CDboTSClickNPC
			{
				npcidx = "3331103;";
			}
			CDboTSCheckClrQst
			{
				flink = 1;
				flinknextqid = "1322;";
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
				conv = 132109;
				ctype = 1;
				idx = 3331103;
				taid = 2;
			}
			CDboTSActSToCEvt
			{
				apptype = 0;
				cnt1 = 0;
				eitype = 0;
				idx0 = 4262105;
				cnt0 = 7;
				cnt2 = 0;
				ectype = -1;
				etype = 0;
				idx1 = -1;
				taid = 3;
				esctype = 0;
				idx2 = -1;
			}
			CDboTSActRegQInfo
			{
				cont = 132108;
				area = 132101;
				goal = 132104;
				m0fz = "4223.000000";
				m0widx = 1;
				scitem = -1;
				sort = 132105;
				stype = 1;
				m0fy = "0.000000";
				m0pat = 2;
				grade = 132203;
				m0fx = "2885.000000";
				m0ttip = 132115;
				rwd = 100;
				taid = 1;
				title = 132102;
				gtype = 2;
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
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 132114;
			nextlnk = 101;
			rwdexp = 0;
			rwdtbl = 132101;
			rwdtype = 0;
			ltime = -1;
			prelnk = "3;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "3331103;";
			}
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 132108;
			gtype = 2;
			oklnk = 2;
			area = 132101;
			goal = 132104;
			sort = 132105;
			prelnk = "0;";
			ds = 1;
			grade = 132203;
			rwd = 100;
			title = 132102;
		}
	}
}

