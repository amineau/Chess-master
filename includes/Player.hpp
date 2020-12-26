class Player {
    
public:
    Player();
	Player( bool isWhite );
	Player( Player const & );
    ~Player();

    Player &	operator=( Player const & );

    bool        isWhite(void) const;
private:
    bool _isWhite;
};
