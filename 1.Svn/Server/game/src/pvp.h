//Find
		~CPVP();
		
///Change
#if defined(__BL_ADVANCED_DUEL__)
		virtual ~CPVP();
#else
		~CPVP();
#endif

//Find
		void	Win(DWORD dwPID);
		
///Change
#if defined(__BL_ADVANCED_DUEL__)	
		virtual void	Win(DWORD dwPID);
#else
		void	Win(DWORD dwPID);
#endif

///Add after CPVP class
#if defined(__BL_ADVANCED_DUEL__)
class CAdvancedPVP : public CPVP
{
public:
	enum class EFLAG : std::uint8_t
	{
		AdvancedDuel = 1 << 0,
		Potion = 1 << 1,
		Equip_Change = 1 << 2,
		Mount = 1 << 3,
	};

	class SPlayerStuff
	{
	public:
		SPlayerStuff(LPCHARACTER m_ch, std::vector<LPITEM>&& m_DuelItems, long m_Gold, bool bMountRestrict);
		~SPlayerStuff() = default;
		
		void Win(LPCHARACTER ch) const;
		void GiveMyStuffBack() const;

	private:
		LPCHARACTER ch; // Owner
		std::vector<LPITEM> vDuelItems;
		long lGold;
	};

	CAdvancedPVP(CPVP& v, LPCHARACTER ch_1, LPCHARACTER ch_2);
	~CAdvancedPVP() = default;

	void Win(DWORD dwPID) override;

	static constexpr bool IsForbidden(EFLAG e, std::uint8_t m_Flag)
	{
		return m_Flag & static_cast<std::uint8_t>(e);
	}

	constexpr bool IsForbidden(EFLAG e) const
	{
		return IsForbidden(e, uFlag);
	}

private:
	std::array<std::unique_ptr< SPlayerStuff >, 2> arrPlayerStuff;
	std::uint8_t uFlag; // EFLAG
};
#endif

//Find
	virtual ~CPVPManager();
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	CAdvancedPVP*	GetAdvancedPVP(const LPCHARACTER pkChr) const;
#endif

//Find
	void			Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim);
	
///Change
#if defined(__BL_ADVANCED_DUEL__)
	void			Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim, bool bIsAdvanced = false);
#else
	void			Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim);
#endif